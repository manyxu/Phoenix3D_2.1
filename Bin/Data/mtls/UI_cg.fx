// UI.fx

float4x4 PVWMatrix;
sampler2D Sampler;

void v_UI
(
    in float3 modelPosition : POSITION,
	in float4 modelColor0 : COLOR,
    in float2 modelTCoord0 : TEXCOORD0,
    out float4 clipPosition : POSITION,
	out float4 vertexColor0 : COLOR,
    out float2 vertexTCoord0 : TEXCOORD0
)
{
    clipPosition = mul(PVWMatrix, float4(modelPosition,1.0f));

    vertexColor0 = modelColor0;

    vertexTCoord0 = modelTCoord0;
}

void p_UI
(
    in float4 vertexColor0 : COLOR,
    in float2 vertexTCoord0 : TEXCOORD0,
    out float4 pixelColor : COLOR
)
{
    pixelColor = tex2D(Sampler, float2(vertexTCoord0.x, 1.0f-vertexTCoord0.y));
    pixelColor *= vertexColor0;
}