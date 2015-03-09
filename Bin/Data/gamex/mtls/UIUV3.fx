// UIUV3.fx

float4x4 gPVWMatrix;
sampler2D gDiffuseSampler;
sampler2D gAddedSampler;
sampler2D gMaskSampler;
float4 gAddedColor;

void v_UIUV3
(
    in float3 modelPosition : POSITION,
	in float4 modelColor0 : COLOR,
    in float2 modelTCoord0 : TEXCOORD0,
	in float2 modelTCoord1 : TEXCOORD1,
	in float2 modelTCoord2 : TEXCOORD2,
    out float4 clipPosition : POSITION,
	out float4 vertexColor0 : COLOR,
    out float2 vertexTCoord0 : TEXCOORD0,
	out float2 vertexTCoord1 : TEXCOORD1,
	out float2 vertexTCoord2 : TEXCOORD2
)
{
    clipPosition = mul(gPVWMatrix, float4(modelPosition,1.0f));

    vertexColor0 = modelColor0;	

    vertexTCoord0 = modelTCoord0;
	vertexTCoord1 = modelTCoord1;
	vertexTCoord2 = modelTCoord2;
}

void p_UIUV3
(
    in float4 vertexColor0 : COLOR,
    in float2 vertexTCoord0 : TEXCOORD0,
	in float2 vertexTCoord1 : TEXCOORD1,
	in float2 vertexTCoord2 : TEXCOORD2,
    out float4 pixelColor : COLOR
)
{
    float4 pixelColor0 = tex2D(gDiffuseSampler, float2(vertexTCoord0.x, 1.0f-vertexTCoord0.y));
	float4 pixelColor1 = tex2D(gAddedSampler, float2(vertexTCoord1.x, 1.0f-vertexTCoord1.y));
	float4 pixelColor2 = tex2D(gMaskSampler, float2(vertexTCoord2.x, 1.0f-vertexTCoord2.y));	

	float4 addedColor;
	addedColor.rgb = (pixelColor0*vertexColor0).rgb + (pixelColor1*gAddedColor).rgb * gAddedColor.a;
	addedColor.a = pixelColor0.a;
    
	pixelColor = addedColor * pixelColor2;
}