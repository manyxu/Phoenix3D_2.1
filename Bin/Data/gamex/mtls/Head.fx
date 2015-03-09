// Head.fx

float4x4 gWMatrix;
float4x4 gVMatrix;
float4x4 gPMatrix;
float4x4 gPVWMatrix;
float4x4 gVWMatrix;
float4x4 gWIMatrix;
float4x4 gVIMatrix;

// ------------------------------------------- camera
float4 gCameraModelPosition = float4(1.0f, 1.0f, 1.0f, 1.0f);
float4 gCameraWorldPosition = float4(1.0f, 1.0f, 1.0f, 1.0f);
float4 gCameraModelDVector = float4(1.0f, 1.0f, 1.0f, 1.0f);
float4 gCameraWorldDVector = float4(1.0f, 1.0f, 1.0f, 1.0f);

// ------------------------------------------- shine
float4 gShineEmissive = float4(0.0f, 0.0f, 0.0f, 1.0f);
float4 gShineAmbient  = float4(0.1f, 0.1f, 0.1f, 1.0f);
float4 gShineDiffuse  = float4(0.47f, 0.47f, 0.47f, 1.0f);

// ------------------------------------------- light
float4 gLightColour = float4(0.3f, 0.3f, 0.3f, 1.0f);
float4 gLightModelDirection = float4(-0.5f, -0.5f, -0.5f, 1.0f);
float4 gLightWorldDirection = float4(-0.5f, -0.5f, -0.5f, 1.0f);

// ------------------------------------------- user
float4 gUser = float4(1.0f, 1.0f, 1.0f, 1.0f);

// ------------------------------------------- functions
float3 NormalCalc(float3 mapNorm, float BumpScale)
{
	float3 v = {0.5f,0.5f,1.0f};
	mapNorm = lerp(v, mapNorm, BumpScale );
	mapNorm = ( mapNorm * 2.0f ) - 1.0f;
	return mapNorm;
}