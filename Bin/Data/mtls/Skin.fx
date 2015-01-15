// The application can changes these parameters at run time.

float4x4 gPVWMatrix;
float4 gBoneTM[114];
float4 CameraWorldPosition;
float4 gShineEmissive;
float4 gShineAmbient;
float4 gShineDiffuse;
float4 gShineSpecular;
float4 gLightAmbient;
float4 gLightDiffuse;
float4 gLightSpecular;
float4 FogParam;
float4 LightWorldDirection;

sampler2D gDiffuseSampler = sampler_state
{
   MinFilter = Nearest;
   MagFilter = Nearest;
   WrapS     = Clamp;
   WrapT     = Clamp;
};

void SkinPosition (float3 inPos, float m_wt, int m_indx, float3 skinned_position)
{
	float4 tmp; 
	tmp.x = dot(inPos, gBoneTM[m_indx]);
	tmp.y = dot(inPos, gBoneTM[m_indx + 1]);
	tmp.z = dot(inPos, gBoneTM[m_indx + 2]);
	skinned_position += m_wt * tmp;
}

void v_Skin
(
    in float3 modelPosition : POSITION,
	in float3 modelNormal : NORMAL,
    in float2 modelTCoord0 : TEXCOORD0,
	in float4 modelTCoord1 : TEXCOORD1, // indeces
	in float4 modelTCoord2 : TEXCOORD2, // wights
    out float4 clipPosition : POSITION,
	out float4 vertexColor : COLOR,
    out float2 vertexTCoord0 : TEXCOORD0,
	out float2 vertexTCoord1 : TEXCOORD1
)
{
	int i0 = modelTCoord1[0]*3;
	int i1 = modelTCoord1[1]*3;
	int i2 = modelTCoord1[2]*3;
	int i3 = modelTCoord1[3]*3;
	float4 weight = modelTCoord2;
	
	float4 inputPos = float4(modelPosition, 1.0f);
	float3 pos = float3(0, 0, 0);	
	pos += float3(dot(inputPos, gBoneTM[i0]), dot(inputPos, gBoneTM[i0 + 1]), dot(inputPos, gBoneTM[i0 + 2])) * weight[0];
	pos += float3(dot(inputPos, gBoneTM[i1]), dot(inputPos, gBoneTM[i1 + 1]), dot(inputPos, gBoneTM[i1 + 2])) * weight[1];
	pos += float3(dot(inputPos, gBoneTM[i2]), dot(inputPos, gBoneTM[i2 + 1]), dot(inputPos, gBoneTM[i2 + 2])) * weight[2];	
	pos += float3(dot(inputPos, gBoneTM[i3]), dot(inputPos, gBoneTM[i3 + 1]), dot(inputPos, gBoneTM[i3 + 2])) * weight[3];
	float3 normal = float3(0, 0, 0);
	normal += float3(dot(modelNormal, gBoneTM[i0]), dot(modelNormal, gBoneTM[i0 + 1]), dot(modelNormal, gBoneTM[i0 + 2])) * weight[0];
	normal += float3(dot(modelNormal, gBoneTM[i1]), dot(modelNormal, gBoneTM[i1 + 1]), dot(modelNormal, gBoneTM[i1 + 2])) * weight[1];
	normal += float3(dot(modelNormal, gBoneTM[i2]), dot(modelNormal, gBoneTM[i2 + 1]), dot(modelNormal, gBoneTM[i2 + 2])) * weight[2];	
	normal += float3(dot(modelNormal, gBoneTM[i3]), dot(modelNormal, gBoneTM[i3 + 1]), dot(modelNormal, gBoneTM[i3 + 2])) * weight[3];
	normal = normalize(normal);
	
	clipPosition = mul(gPVWMatrix, float4(pos, 1.0f));
	
	float3 viewVector = normalize(CameraWorldPosition.rgb - pos);
	
	// light
	float3 halfVector = normalize((viewVector - LightWorldDirection.rgb)/2.0);
	float dotH = dot(normal, halfVector);
	
	vertexColor.rgb = gShineEmissive.rgb + gShineAmbient.rgb * gLightAmbient.rgb +
		gShineDiffuse.rgb * gLightDiffuse.rgb * max(dot(normal, -LightWorldDirection.rgb), 0) +
							gShineSpecular.rgb * gLightSpecular.rgb * pow(max(dotH, 0), gShineSpecular.a*gLightSpecular.a);		
	vertexColor.a = gShineDiffuse.a;

    vertexTCoord0 = modelTCoord0;
	
	float dist = distance(CameraWorldPosition.rgb, pos);
	
	// fog
	float fogValue = (FogParam.y - dist)/(FogParam.y - FogParam.x);
	fogValue = clamp(fogValue, 0, 1.0);
	
	float fogValueHeight = (-FogParam.z + pos.z)/(FogParam.w - FogParam.z);
	fogValueHeight = clamp(fogValueHeight, 0, 1.0);	
	
	vertexTCoord1.x = fogValue;
	vertexTCoord1.y = fogValueHeight;
}

void p_Skin
(
	in float4 vertexColor : COLOR,
    in float2 vertexTCoord0 : TEXCOORD0,
	in float2 vertexTCoord1 : TEXCOORD1,
    out float4 pixelColor : COLOR,
	uniform float4 FogColor
)
{
    // Sample the texture image.
    float2 texCoord = vertexTCoord0;
    texCoord.y = 1.0 - vertexTCoord0.y;
    float4 lastColor = tex2D(gDiffuseSampler, texCoord);
	lastColor *= vertexColor;
		
	lastColor.rgb = lerp(FogColor.rgb, lastColor.rgb, vertexTCoord1.x);
	lastColor.rgb = lerp(FogColor.rgb, lastColor.rgb, vertexTCoord1.y);	
	pixelColor = lastColor;
}
