// UIDark.fx

float4x4 gPVWMatrix;
sampler2D gDiffuseSampler;
float4 gScaleParam;

void v_UIDark
(
    in float3 modelPosition : POSITION,
	in float4 modelColor0 : COLOR,
    in float2 modelTCoord0 : TEXCOORD0,
    out float4 clipPosition : POSITION,
	out float4 vertexColor0 : COLOR,
    out float2 vertexTCoord0 : TEXCOORD0
)
{
    clipPosition = mul(gPVWMatrix, float4(modelPosition,1.0f));

    vertexColor0 = modelColor0;

    vertexTCoord0 = modelTCoord0;
}

void p_UIDark
(
    in float4 vertexColor0 : COLOR,
    in float2 vertexTCoord0 : TEXCOORD0,
    out float4 pixelColor : COLOR
)
{
    pixelColor = tex2D(gDiffuseSampler, float2(vertexTCoord0.x, 1.0f-vertexTCoord0.y));
    pixelColor *= vertexColor0;
	float h = 0.3*pixelColor.r + 0.59*pixelColor.g + 0.11*pixelColor.b;
	pixelColor = float4(h, h, h, pixelColor.a)*gScaleParam.x +pixelColor*(1.0-gScaleParam.x);
}