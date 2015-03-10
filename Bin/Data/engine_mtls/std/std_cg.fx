
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
	uniform float4 LightWorldDVector_Dir,
	uniform float4 ShineEmissive,
	uniform float4 ShineAmbient,
	uniform float4 ShineDiffuse,
	uniform float4 ShineSpecular,	
	uniform float4 LightAmbient_Dir,
	uniform float4 LightDiffuse_Dir,
	uniform float4 LightSpecular_Dir,
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
	float3 halfVector = normalize((viewVector - LightWorldDVector_Dir.xyz)/2.0);
	float dotH = dot(worldNormal, halfVector);
	
	// fog
	float fogValueHeight = (-FogParam.x + worldPosition.z)/(FogParam.y - FogParam.x);
	fogValueHeight = clamp(fogValueHeight, 0, 1.0);	
	
	float fogValueDist = (FogParam.w - dist)/(FogParam.w - FogParam.z);
	fogValueDist = clamp(fogValueDist, 0, 1.0);

	// pass Datas
	vertexColor.rgb = ShineEmissive.rgb + ShineAmbient.rgb * LightAmbient_Dir.rgb +
		ShineDiffuse.rgb * LightDiffuse_Dir.rgb * max(dot(worldNormal, -LightWorldDVector_Dir.rgb), 0) +
							ShineSpecular.rgb * LightSpecular_Dir.rgb * pow(max(dotH, 0), ShineSpecular.a*LightSpecular_Dir.a);		
	vertexColor.a = ShineDiffuse.a;
	
	vertexTCoord1.x = fogValueDist;
	vertexTCoord1.y = fogValueHeight;
}

sampler2D Sample0 = sampler_state
{
   MinFilter = Nearest;
   MagFilter = Nearest;
   WrapS     = Clamp;
   WrapT     = Clamp;
};

void p_std
(
	in float4 vertexColor : COLOR,
    in float2 vertexTCoord0 : TEXCOORD0,
	in float2 vertexTCoord1 : TEXCOORD1,
    out float4 pixelColor : COLOR,
	uniform float4 FogColorHeight,
	uniform float4 FogColorDist
)
{
    // Sample the texture image.
    float2 texCoord = vertexTCoord0;
    texCoord.y = 1.0 - vertexTCoord0.y;
	float4 lastColor = tex2D(Sample0, texCoord);
	lastColor *= vertexColor;
			
	lastColor.rgb = lerp(FogColorHeight.rgb, lastColor.rgb, vertexTCoord1.y);
	lastColor.rgb = lerp(FogColorDist.rgb, lastColor.rgb, vertexTCoord1.x);
		
	pixelColor = lastColor;
}
