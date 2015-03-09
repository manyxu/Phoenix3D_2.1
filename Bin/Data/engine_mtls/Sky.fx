// Standard.fx

// ------------------------------------------- constants
// float4 sunParams = float4(512.0f, 0.2f, 400.0f, 0.2f); // sunRadiusAttenuation,sunLightness,largeSunRadiusAttenuation,largeSunLightness
// float4 skyParams = float4(50.0f, 2.0f, 0.0f, 0.0f); // hazeTopAltitude, dayToSunsetSharpness

// ------------------------------------------- texs
sampler2D gDaySampler;
sampler2D gSunsetSampler;
sampler2D gNightSampler;

// ------------------------------------------- shaders
void v_Sky
(
	in float3 modelPosition : POSITION,
	out float4 clipPosition : POSITION,
	out float3 camToVertex : TEXCOORD0,
	uniform float4x4 gPVWMatrix,
	uniform float4x4 gVMatrix,
	uniform float4 gCameraWorldPosition
)
{	
	clipPosition = mul(gPVWMatrix, float4(modelPosition, 1.0f));
	float4 worldPosition = mul(gVMatrix, float4(modelPosition, 1.0f));
	camToVertex = worldPosition.xyz - gCameraWorldPosition.xyz;
}

void p_Sky
(
	in float3 camToVertex : TEXCOORD0,
	out float4 pixelColor : COLOR,
	uniform float4 gLightWorldDirection,
	uniform float4 gCameraWorldDVector,
	uniform float4 gLightColour,
	uniform float4 sunParams,
	uniform float4 skyParams
)
{
	camToVertex = normalize(camToVertex);

	float sunHighLight = pow(max(0, dot(camToVertex, -gLightWorldDirection.xyz)), sunParams[0]) * sunParams[1];
	float largeSunHighLight = pow(max(0, dot(camToVertex, -gLightWorldDirection.xyz)), sunParams[2]) * sunParams[3];
	
	float3 flatLightVec = normalize(float3(-gLightWorldDirection.x, -gLightWorldDirection.y, 0.0f));
	float3 flatCameraVec = normalize(float3(gCameraWorldDVector.x, gCameraWorldDVector.y, 0.0f));
	float lcDot = dot(flatLightVec, flatCameraVec);
	float u =  1.0f - (lcDot + 1.0f) * 0.5f;
	
	float val = lerp(0.25, 1.25, min(1, skyParams[0] / max(0.0001, -gLightWorldDirection.z)));	
	float yAngle = pow(max(0, camToVertex.z), val);	
	float v =  1.0f - yAngle;
	
	float4 colorDay = tex2D(gDaySampler, float2(u, v));
	float4 colorSunSet = tex2D(gSunsetSampler, float2(u, v));
	float4 colorNight = tex2D(gNightSampler, float2(u, v));
	
	float4 color = float4(0,0,0,1);
	if (-gLightWorldDirection.z > 0)
	{
		color = lerp(colorDay, colorSunSet, min(1, pow(1 + gLightWorldDirection.z, skyParams[1])));
	}
	else
	{
		color = lerp(colorSunSet, colorNight, min(1, gLightWorldDirection.z * 4));
	}
	
	color += gLightColour * (sunHighLight + largeSunHighLight);
	
	pixelColor = color;
}