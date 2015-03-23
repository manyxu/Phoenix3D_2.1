float3 DoLight_Point_Diffuse(float3 lightWorldPos, float lightRange, float3 lightColor, float3 shineDiffuse,float3 vertexWorldPos, float3 vertexWorldNormal)
{
	float3 lightToVertex = lightWorldPos - vertexWorldPos;
	float squareDist = dot(lightToVertex, lightToVertex);
	lightToVertex = normalize(lightToVertex);
	return lightColor * shineDiffuse * max(0, dot(vertexWorldNormal, lightToVertex)) * max( 0, (1.0 - squareDist / lightRange / lightRange) );
}

void v_std_lightshadow
(
    in float3 modelPosition : POSITION,
	in float3 modelNormal : NORMAL,
    in float2 modelTCoord0 : TEXCOORD0,
    out float4 clipPosition : POSITION,
	out float4 vertexColor : COLOR,
    out float2 vertexTCoord0 : TEXCOORD0,
	out float2 vertexTCoord1 : TEXCOORD1,
	out float4 vertexTCoord2 : TEXCOORD2,
    uniform float4x4 PVWMatrix,
	uniform float4x4 WMatrix,
    uniform float4x4 ProjectPVBSMatrix_Dir,
	uniform float4 CameraWorldPosition,
	uniform float4 LightWorldDVector_Dir,
	uniform float4 ShineEmissive,
	uniform float4 ShineAmbient,
	uniform float4 ShineDiffuse,
	uniform float4 ShineSpecular,	
	uniform float4 LightAmbient_Dir,
	uniform float4 LightDiffuse_Dir,
	uniform float4 LightSpecular_Dir,
	uniform float4 LightGroup[8],
	uniform float4 FogParam
)
{
    // Pos
    clipPosition = mul(PVWMatrix, float4(modelPosition,1.0f));

    // Tex Coord
    vertexTCoord0 = modelTCoord0;
	
	// params
	float4 worldPosition = mul(WMatrix, float4(modelPosition, 1.0f));
	float3 worldNormal = normalize(mul((float3x3)WMatrix, modelNormal));	
	
	float3 viewVector = normalize(CameraWorldPosition.xyz - worldPosition.xyz);
	float dist = distance(CameraWorldPosition.xyz, worldPosition.xyz);
	
	// light
	float3 halfVector = normalize((viewVector - LightWorldDVector_Dir.xyz)/2.0);
	float dotH = dot(worldNormal, halfVector);
	
	vertexColor.rgb = ShineEmissive.rgb + LightAmbient_Dir.a * (ShineAmbient.rgb * LightAmbient_Dir.rgb +
		ShineDiffuse.rgb * LightDiffuse_Dir.rgb * max(dot(worldNormal, -LightWorldDVector_Dir.rgb), 0) +
							ShineSpecular.rgb * LightSpecular_Dir.rgb * pow(max(dotH, 0), ShineSpecular.a*LightSpecular_Dir.a));		
	vertexColor.a = ShineDiffuse.a;
	
	// point lights
	vertexColor.rgb += DoLight_Point_Diffuse(LightGroup[0].xyz, LightGroup[0].w, LightGroup[1].rgb, ShineDiffuse.rgb, worldPosition.xyz, worldNormal.xyz);
	vertexColor.rgb += DoLight_Point_Diffuse(LightGroup[2].xyz, LightGroup[2].w, LightGroup[3].rgb, ShineDiffuse.rgb, worldPosition.xyz, worldNormal.xyz);
	vertexColor.rgb += DoLight_Point_Diffuse(LightGroup[4].xyz, LightGroup[4].w, LightGroup[5].rgb, ShineDiffuse.rgb, worldPosition.xyz, worldNormal.xyz);
	vertexColor.rgb += DoLight_Point_Diffuse(LightGroup[6].xyz, LightGroup[6].w, LightGroup[7].rgb, ShineDiffuse.rgb, worldPosition.xyz, worldNormal.xyz);
	
	// fog
	float fogValueHeight = (-FogParam.x + worldPosition.z)/(FogParam.y - FogParam.x);
	fogValueHeight = clamp(fogValueHeight, 0, 1.0);	
	float fogValueDist = (FogParam.w - dist)/(FogParam.w - FogParam.z);
	fogValueDist = clamp(fogValueDist, 0, 1.0);
	
	vertexTCoord1.x = fogValueDist;
	vertexTCoord1.y = fogValueHeight;
	
	// shadow
    vertexTCoord2 = mul(ProjectPVBSMatrix_Dir, float4(modelPosition, 1.0f));
}

sampler2D SampleBase = sampler_state
{
   MinFilter = Nearest;
   MagFilter = Nearest;
   WrapS     = Clamp;
   WrapT     = Clamp;
};

sampler2D SampleShadowDepth = sampler_state
{
   MinFilter = Nearest;
   MagFilter = Linear;
   WrapS     = Clamp;
   WrapT     = Clamp;
};

void p_std_lightshadow
(
	in float4 vertexColor : COLOR,
    in float2 vertexTCoord0 : TEXCOORD0,
	in float2 vertexTCoord1 : TEXCOORD1,
	in float4 vertexTCoord2 : TEXCOORD2,
    out float4 pixelColor : COLOR,
	uniform float4 FogColorHeight,
	uniform float4 FogColorDist
)
{
    // base
    float2 texCoord = vertexTCoord0;
    texCoord.y = 1.0 - vertexTCoord0.y;
	float4 lastColor = tex2D(SampleBase, texCoord);
	
	// light
	lastColor *= vertexColor;
	
	// shadow
	float4 texCord = vertexTCoord2;

	//float depth = texCord.z;
	//float depthVal = tex2D(SampleShadowDepth, texCord.xy).r;
	
	float depth = texCord.z/texCord.w;
	float4 depthColor = tex2Dproj(SampleShadowDepth, texCord);
	float depthVal = depthColor.x*255+depthColor.y;
	
	float lightAmout = 1.0f;
	if (depth > depthVal) lightAmout = 0.0f;
	lastColor.rgb *= lightAmout;
	
	// fog
	lastColor.rgb = lerp(FogColorHeight.rgb, lastColor.rgb, vertexTCoord1.y);
	lastColor.rgb = lerp(FogColorDist.rgb, lastColor.rgb, vertexTCoord1.x);
		
	pixelColor = lastColor;
}
