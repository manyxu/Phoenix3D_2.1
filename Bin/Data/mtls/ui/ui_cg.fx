// UI.fx

float4x4 PVWMatrix;
sampler2D DiffuseSampler;

void v_UI
(
    in float3 modelPosition : POSITION,
    in float2 modelTCoord0 : TEXCOORD0,
    out float4 clipPosition : POSITION,
    out float2 vertexTCoord0 : TEXCOORD0
)
{
    clipPosition = mul(PVWMatrix, float4(modelPosition,1.0f));

    vertexTCoord0 = modelTCoord0;
}

void p_UI
(
    in float2 vertexTCoord0 : TEXCOORD0,
    out float4 pixelColor : COLOR
)
{
    pixelColor = tex2D(DiffuseSampler, float2(vertexTCoord0.x, 1.0f-vertexTCoord0.y));
}