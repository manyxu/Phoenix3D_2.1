// Standard.fx

// ------------------------------------------- diffuse
sampler2D gDiffuseSampler;

// ------------------------------------------- shader
void v_VertexColorStd
(
	in float3 modelPosition : POSITION,
	in float4 modelColor0 : COLOR,
	in float3 modelNormal : NORMAL,
	in float2 modelTCoord0 : TEXCOORD0,
	out float4 clipPosition : POSITION,
	out float2 vertexTCoord0 : TEXCOORD0,
	out float4 vertexTCoord1 : TEXCOORD1,
	uniform float4x4 gPVWMatrix,
	uniform float4 gShineEmissive,
	uniform float4 gShineAmbient,
	uniform float4 gShineDiffuse,
	uniform float4 gLightAmbient,
	uniform float4 gLightDiffuse,
	uniform float4 gLightModelDirection
)
{
	clipPosition = mul(gPVWMatrix, float4(modelPosition,1.0f));	
	
	vertexTCoord0 = modelTCoord0;
	
	vertexTCoord1.rgb = gShineEmissive.rgb
		+ gLightAmbient.rgb*gShineAmbient.rgb
		+ gLightDiffuse.rgb*gShineDiffuse.rgb*max(0, dot(modelNormal, -gLightModelDirection.rgb));
	vertexTCoord1.a = gShineDiffuse.a;
	vertexTCoord1 *= modelColor0;
}

void p_VertexColorStd
(
	in float2 vertexTCoord0 : TEXCOORD0,
	in float4 vertexTCoord1 : TEXCOORD1,
	out float4 pixelColor : COLOR
)
{
    float2 texCoord = vertexTCoord0;
    texCoord.y = 1.0 - vertexTCoord0.y;
	float4 finalColor = tex2D(gDiffuseSampler, texCoord);
	finalColor *= vertexTCoord1;
	pixelColor = finalColor;
}