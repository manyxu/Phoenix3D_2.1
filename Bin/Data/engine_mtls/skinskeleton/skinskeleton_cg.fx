// The application can changes these parameters at run time.

float4x4 PVWMatrix;
float4 BoneTM[114];
float4 CameraWorldPosition;
float4 LightWorldDirection_Dir;
float4 ShineEmissive;
float4 ShineAmbient;
float4 ShineDiffuse;
float4 ShineSpecular;
float4 LightAmbient_Dir;
float4 LightDiffuse_Dir;
float4 LightSpecular_Dir;
float4 FogParam;

void SkinPosition (float3 inPos, float m_wt, int m_indx, float3 skinned_position)
{
	float4 tmp; 
	tmp.x = dot(inPos, BoneTM[m_indx]);
	tmp.y = dot(inPos, BoneTM[m_indx + 1]);
	tmp.z = dot(inPos, BoneTM[m_indx + 2]);
	skinned_position += m_wt * tmp;
}

void v_skinskeleton
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
	pos += float3(dot(inputPos, BoneTM[i0]), dot(inputPos, BoneTM[i0 + 1]), dot(inputPos, BoneTM[i0 + 2])) * weight[0];
	pos += float3(dot(inputPos, BoneTM[i1]), dot(inputPos, BoneTM[i1 + 1]), dot(inputPos, BoneTM[i1 + 2])) * weight[1];
	pos += float3(dot(inputPos, BoneTM[i2]), dot(inputPos, BoneTM[i2 + 1]), dot(inputPos, BoneTM[i2 + 2])) * weight[2];	
	pos += float3(dot(inputPos, BoneTM[i3]), dot(inputPos, BoneTM[i3 + 1]), dot(inputPos, BoneTM[i3 + 2])) * weight[3];
	float3 normal = float3(0, 0, 0);
	normal += float3(dot(modelNormal, BoneTM[i0]), dot(modelNormal, BoneTM[i0 + 1]), dot(modelNormal, BoneTM[i0 + 2])) * weight[0];
	normal += float3(dot(modelNormal, BoneTM[i1]), dot(modelNormal, BoneTM[i1 + 1]), dot(modelNormal, BoneTM[i1 + 2])) * weight[1];
	normal += float3(dot(modelNormal, BoneTM[i2]), dot(modelNormal, BoneTM[i2 + 1]), dot(modelNormal, BoneTM[i2 + 2])) * weight[2];	
	normal += float3(dot(modelNormal, BoneTM[i3]), dot(modelNormal, BoneTM[i3 + 1]), dot(modelNormal, BoneTM[i3 + 2])) * weight[3];
	normal = normalize(normal);
	
	clipPosition = mul(PVWMatrix, float4(pos, 1.0f));
	
	float3 viewVector = normalize(CameraWorldPosition.rgb - pos);
	
	// light
	float3 halfVector = normalize((viewVector - LightWorldDirection_Dir.rgb)/2.0);
	float dotH = dot(normal, halfVector);
	
	vertexColor.rgb = ShineEmissive.rgb + ShineAmbient.rgb * LightAmbient_Dir.rgb +
		ShineDiffuse.rgb * LightDiffuse_Dir.rgb * max(dot(normal, -LightWorldDirection_Dir.rgb), 0) +
							ShineSpecular.rgb * LightSpecular_Dir.rgb * pow(max(dotH, 0), ShineSpecular.a*LightSpecular_Dir.a);		
	vertexColor.a = ShineDiffuse.a;

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

sampler2D SampleBase;

void p_skinskeleton
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
    float4 lastColor = tex2D(SampleBase, texCoord);
	lastColor *= vertexColor;
		
	lastColor.rgb = lerp(FogColor.rgb, lastColor.rgb, vertexTCoord1.x);
	lastColor.rgb = lerp(FogColor.rgb, lastColor.rgb, vertexTCoord1.y);	
	pixelColor = lastColor;
}
