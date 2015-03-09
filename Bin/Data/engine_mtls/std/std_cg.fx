// The application can changes these parameters at run time.
sampler2D BaseSampler = sampler_state
{
   MinFilter = Nearest;
   MagFilter = Nearest;
   WrapS     = Clamp;
   WrapT     = Clamp;
};

void v_std
(
    in float3 modelPosition : POSITION,
	in float3 modelNormal : NORMAL,
    in float2 modelTCoord0 : TEXCOORD0,
    out float4 clipPosition : POSITION,
	out float4 vertexColor : COLOR,
    out float2 vertexTCoord0 : TEXCOORD0,
	out float2 vertexTCoord1 : TEXCOORD1,
    uniform float4x4 PVWMatrix,
	uniform float4x4 WMatrix,
	uniform float4 CameraWorldPosition,
	uniform float4 LightWorldDirection,
	uniform float4 ShineEmissive,
	uniform float4 ShineAmbient,
	uniform float4 ShineDiffuse,
	uniform float4 ShineSpecular,	
	uniform float4 LightAmbient,
	uniform float4 LightDiffuse,
	uniform float4 LightSpecular,
	uniform float4 FogParam
)
{
    // Transform the position from model space to clip space.
    clipPosition = mul(PVWMatrix, float4(modelPosition,1.0f));

    // Pass through the texture coordinate.
    vertexTCoord0 = modelTCoord0;
	
	// params
	float3 worldPosition = mul(WMatrix, float4(modelPosition, 1.0f)).xyz;
	float3 worldNormal = normalize(mul((float3x3)WMatrix, modelNormal));	
	
	float3 viewVector = normalize(CameraWorldPosition.xyz - worldPosition);
	float dist = distance(CameraWorldPosition.xyz, worldPosition);
	
	// light
	float3 halfVector = normalize((viewVector - LightWorldDirection.xyz)/2.0);
	float dotH = dot(worldNormal, halfVector);
	
	// fog
	float fogValue = (FogParam.y - dist)/(FogParam.y - FogParam.x);
	fogValue = clamp(fogValue, 0, 1.0);
	
	float fogValueHeight = (-FogParam.z + worldPosition.z)/(FogParam.w - FogParam.z);
	fogValueHeight = clamp(fogValueHeight, 0, 1.0);	

	// pass Datas
	vertexColor.rgb = ShineEmissive.rgb + ShineAmbient.rgb * LightAmbient.rgb +
		ShineDiffuse.rgb * LightDiffuse.rgb * max(dot(worldNormal, -LightWorldDirection.rgb), 0) +
							ShineSpecular.rgb * LightSpecular.rgb * pow(max(dotH, 0), ShineSpecular.a*LightSpecular.a);		
	vertexColor.a = ShineDiffuse.a;
	
	vertexTCoord1.x = fogValue;
	vertexTCoord1.y = fogValueHeight;
}

void p_std
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
	float4 lastColor = tex2D(BaseSampler, texCoord);
	lastColor *= vertexColor;
		
	lastColor.rgb = lerp(FogColor.rgb, lastColor.rgb, vertexTCoord1.x);
	lastColor.rgb = lerp(FogColor.rgb, lastColor.rgb, vertexTCoord1.y);	
	
	pixelColor = lastColor;
}
