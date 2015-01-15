// UI.fx

float4x4 PVWMatrix;
sampler2D Sampler0;

void v_ui
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

void p_ui
(
    in float2 vertexTCoord0 : TEXCOORD0,
    out float4 pixelColor : COLOR
)
{
    pixelColor = tex2D(Sampler0, float2(vertexTCoord0.x, 1.0f-vertexTCoord0.y));
}