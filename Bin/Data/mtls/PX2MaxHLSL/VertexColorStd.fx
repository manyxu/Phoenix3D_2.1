// Standard.fx
#include "Head.fx"

// ------------------------------------------- blend
int gBlendMode
<
	string UIName = "BlendMode";
	string UIType = "IntSpinner";
	float UIMin = 0;
	float UIMax = 4;	
> = 2;
// ------------------------------------------- double side
bool gDoubleSide 
<
	string UIName = "DoubleSide";
> = false;
// ------------------------------------------- diffuse
texture gDiffuseTexture : DiffuseMap
< 
	string UIName = "Diffuse Map";
	int Texcoord = 0;
	int MapChannel = 1;
>;
sampler2D gDiffuseSampler = sampler_state
{
	Texture = <gDiffuseTexture>;
	MinFilter = Linear;
	MagFilter = Linear;
	MipFilter = Linear;
};
// ------------------------------------------- struct 
struct VSIn
{
	float3 Position		: POSITION;
	float4 Colour		: COLOR;
	float3 Normal		: NORMAL;
	float2 UV0			: TEXCOORD0;
};

struct VSOut
{
	float4 Position		: POSITION;
   	float2 UV0			: TEXCOORD0;
	float4 UV1			: TEXCOORD1;
};

struct PSIn
{
   	float2 UV0			: TEXCOORD0;
	float4 UV1			: TEXCOORD1;
};

struct PSOut
{
	float4 Colour		: COLOR0;
};

// ------------------------------------------- shader
VSOut VS(VSIn vsIn) 
{	
	VSOut vsOut;
	
	float3 normalWorld = normalize(mul(vsIn.Normal, (float3x3)WMatrix));
	
   	vsOut.Position = mul(float4(vsIn.Position, 1.0f), PVWMatrix);
	
	vsOut.UV1.rgb = gShineEmissive.rgb
		+ gLightColour.rgb*gShineAmbient.rgb 
		+ gLightColour.rgb*gShineDiffuse.rgb*max(0, dot(normalWorld, gLightDir));
	vsOut.UV1.a = 1.0;
	vsOut.UV1 *= vsIn.Colour;
	
   	vsOut.UV0 = vsIn.UV0;

	return vsOut;
}

PSOut PS(PSIn psIn)
{
	PSOut psOut;

	float4 finalColor = tex2D(gDiffuseSampler, psIn.UV0);
	
	finalColor *= psIn.UV1;
	
	psOut.Colour = finalColor;

	return psOut;
}

technique Default
{
    pass P0 
    {	
#if gBlendMode == 0
        AlphaBlendEnable = FALSE;
#elif gBlendMode == 1
		AlphaBlendEnable = FALSE;
		AlphaTestEnable = TRUE;
		AlphaRef = 50;
		AlphaFunc = GREATEREQUAL;
#elif gBlendMode == 2
		AlphaBlendEnable = TRUE;
		SrcBlend = SRCALPHA;
		DestBlend = INVSRCALPHA;
		ZWriteEnable = FALSE;
		AlphaTestEnable = TRUE;
		AlphaRef = 50;
		AlphaFunc = GREATEREQUAL;
#endif

#if gDoubleSide
	CullMode = NONE;
#elif gDoubleSide
	CullMode = CW;
#endif

		VertexShader	= compile vs_2_0 VS();
		PixelShader		= compile ps_2_0 PS();
    }
}