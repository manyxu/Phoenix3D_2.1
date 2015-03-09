// Head.fx

float4x4 WMatrix   :	WORLD;
float4x4 VMatrix   :	VIEW;
float4x4 PMatrix   :	PROJECTION;
float4x4 PVWMatrix :	WORLDVIEWPROJ;
float4x4 VWMatrix  :	WorldView;
float4x4 WIMatrix  :	WorldI;
float4x4 VIMatrix  :	ViewI;
float3 CameraWorldPosition : WORLDCAMERAPOSITION;

// light(view space)
float3 gLightDir : Direction
<  
	string UIName = "Light"; 
	string Object = "TargetLight";
	int refID = 0;
> = {-0.577, -0.577, 0.577};
float4 gLightColour : LIGHTCOLOR
<
	int LightRef = 0;
> = float4(1.0f, 1.0f, 1.0f, 1.0f);

float4 gShineEmissive
<
  string UIName = "ShineEmissive";
> = float4(0.0f, 0.0f, 0.0f, 1.0f);

float4 gShineAmbient
<
  string UIName = "ShineAmbient";
> = float4( 0.4f, 0.4f, 0.4f, 1.0f );

float4 gShineDiffuse
<
  string UIName = "ShineDiffuse";
> = float4( 1.0f, 1.0f, 1.0f, 1.0f );

float3 NormalCalc(float3 mapNorm, float BumpScale)
{
	float3 v = {0.5f,0.5f,1.0f};
	mapNorm = lerp(v, mapNorm, BumpScale );
	mapNorm = ( mapNorm * 2.0f ) - 1.0f;
	return mapNorm;
}