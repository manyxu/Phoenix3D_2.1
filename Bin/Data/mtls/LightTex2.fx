// The application can changes these parameters at run time.
sampler2D Sampler0 = sampler_state
{
   MinFilter = Nearest;
   MagFilter = Nearest;
   WrapS     = Clamp;
   WrapT     = Clamp;
};

sampler2D Sampler1 = sampler_state
{
   MinFilter = Nearest;
   MagFilter = Nearest;
   WrapS     = Clamp;
   WrapT     = Clamp;
};

void v_LightTex2
(
    in float3 modelPosition : POSITION,
	in float3 modelNormal : NORMAL0,
    in float2 modelTCoord0 : TEXCOORD0,
	in float2 modelTCoord1 : TEXCOORD1,
    out float4 clipPosition : POSITION,
	out float4 vertexColor : COLOR,
    out float2 vertexTCoord : TEXCOORD0,
	out float2 vertexTCoord1 : TEXCOORD1,
	out float2 vertexTCoord2 : TEXCOORD2,
    uniform float4x4 PVWMatrix,
	uniform float4x4 WMatrix,
	uniform float4 CameraWorldPosition,
	uniform float4 LightWorldDirection,
	uniform float4 LightSpecular,
	uniform float4 FogParam
)
{
    // clip pos tex coord
    clipPosition = mul(PVWMatrix, float4(modelPosition,1.0f));
	vertexTCoord = modelTCoord0;
	vertexTCoord1 = modelTCoord1;
	
	// params
	float3 worldPosition = mul(WMatrix, float4(modelPosition, 1.0f)).xyz;
	float3 worldNormal = normalize(mul((float3x3)WMatrix, modelNormal));	
	
	float3 viewVector = normalize(CameraWorldPosition - worldPosition);
	float dist = distance(CameraWorldPosition, worldPosition);
	
	// light
	float3 halfVector = normalize((viewVector - LightWorldDirection)/2.0);
	float dotH = dot(worldNormal, halfVector);
	
	// fog
	float fogValue = (FogParam.y - dist)/(FogParam.y - FogParam.x);
	fogValue = clamp(fogValue, 0, 1.0);
	
	float fogValueHeight = (-FogParam.z + worldPosition.z)/(FogParam.w - FogParam.z);
	fogValueHeight = clamp(fogValueHeight, 0, 1.0);	

	// pass Datas
	vertexColor.rgb = LightSpecular.rgb*pow(max(dotH, 0), LightSpecular.a);
	vertexColor.a = 1.0;
	
	vertexTCoord2.x = fogValue;
	vertexTCoord2.y = fogValueHeight;
}

void p_LightTex2
(
	in float4 vertexColor : COLOR,
    in float2 vertexTCoord : TEXCOORD0,
	in float2 vertexTCoord1 : TEXCOORD1,
	in float2 vertexTCoord2 : TEXCOORD2,
    out float4 pixelColor : COLOR,
	uniform float4 FogColor
)
{
    float2 texCoord = vertexTCoord;
    texCoord.y = 1.0 - vertexTCoord.y;
	
	float2 texCoord1 = vertexTCoord1;
    texCoord1.y = 1.0 - vertexTCoord1.y;	
	
    // Sample the texture images and add the results.
    float4 color0 = tex2D(Sampler0, texCoord);
    float4 color1 = tex2D(Sampler1, texCoord1);
    float4 lastColor = color0*color1 + vertexColor;
	lastColor.rgb = lerp(FogColor.rgb, lastColor.rgb, vertexTCoord2.x);
	pixelColor.rgb = lerp(FogColor.rgb, lastColor.rgb, vertexTCoord2.y);
	pixelColor.a = color0.a;
}
