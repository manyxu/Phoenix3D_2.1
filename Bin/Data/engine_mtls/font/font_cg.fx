// font.fx

float4x4 PVWMatrix;
float4 ShineEmissive;
float4 UVParam;
sampler2D SamplerBase;

void v_font
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

void p_font
(
	in float4 vertexColor0 : COLOR,
    in float2 vertexTCoord0 : TEXCOORD0,
    out float4 pixelColor : COLOR
)
{
    float4 texColor = tex2D(SamplerBase, float2(vertexTCoord0.x, 1.0f-vertexTCoord0.y)*UVParam.xy);
	pixelColor = texColor*vertexColor0*ShineEmissive;
}