// Effect.fx
#include "Head.fx"

sampler2D BaseSampler;

void v_Font
(
    in float3 modelPosition : POSITION,
    in float4 modelColor : COLOR,
	in float2 modelTCoord : TEXCOORD0,
    out float4 clipPosition : POSITION,
	out float4 vertexColor : COLOR,
    out float2 vertexTCoord : TEXCOORD0
)
{
    // transform
    clipPosition = mul(gPVWMatrix, float4(modelPosition,1.0f));

    // pass texture coord
    vertexTCoord = modelTCoord;

    // pass vertex color
    vertexColor = modelColor;
}

void p_Font
(
    in float4 vertexColor : COLOR,
	in float2 vertexTCoord : TEXCOORD0,
    out float4 pixelColor : COLOR
)
{
    pixelColor = tex2D(BaseSampler, vertexTCoord);
    pixelColor *= vertexColor;
}
