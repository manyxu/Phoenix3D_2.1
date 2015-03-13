

attribute mediump vec3 modelPosition;
attribute mediump vec3 modelNormal;
attribute mediump vec2 modelTCoord0;
varying mediump vec4 vertexColor;
varying mediump vec2 vertexTCoord0;
varying mediump vec2 vertexTCoord1;
varying mediump vec4 vertexTCoord2;

uniform mat4 PVWMatrix;
uniform mat4 WMatrix;
uniform mat4 ProjectPVBSMatrix_Dir;
uniform vec4 CameraWorldPosition;
uniform vec4 LightWorldDirection_Dir;
uniform vec4 ShineEmissive;
uniform vec4 ShineAmbient;
uniform vec4 ShineDiffuse;
uniform vec4 ShineSpecular;
uniform vec4 LightAmbient_Dir;
uniform vec4 LightDiffuse_Dir;
uniform vec4 LightSpecular_Dir;
uniform vec4 FogParam;

void main()
{
	gl_Position = PVWMatrix * vec4(modelPosition, 1.0);
	
	vertexTCoord0 = modelTCoord0;
	
	vec3 worldPosition = (WMatrix * vec4(modelPosition, 1.0)).xyz;
	vec4 col0 = WMatrix[0]; vec4 col1 = WMatrix[1]; vec4 col2 = WMatrix[2]; 
	mat3 worldMat = mat3(col0.xyz, col1.xyz, col2.xyz);
	vec3 worldNormal = normalize(worldMat * modelNormal);
	
	vec3 viewVector = normalize(CameraWorldPosition.xyz - worldPosition);
	float dist = sqrt((CameraWorldPosition.x - worldPosition.x)*(CameraWorldPosition.x - worldPosition.x) + (CameraWorldPosition.y - worldPosition.y)*(CameraWorldPosition.y - worldPosition.y) + (CameraWorldPosition.z - worldPosition.z)*(CameraWorldPosition.z - worldPosition.z));
	
	vec3 halfVector = normalize((viewVector - LightWorldDirection_Dir.xyz)/2.0);
	float dotH = dot(worldNormal, halfVector);
	
	vertexColor.rgb = ShineEmissive.rgb + ShineAmbient.rgb * LightAmbient_Dir.rgb + ShineDiffuse.rgb * LightDiffuse_Dir.rgb * max(dot(worldNormal, -LightWorldDirection_Dir.xyz), 0.0) + ShineSpecular.rgb * LightSpecular_Dir.rgb * pow(max(dotH, 0.0), ShineSpecular.a);
	vertexColor.a = LightDiffuse_Dir.a;
	
	float fogValueHeight = (-FogParam.z + worldPosition.z)/(FogParam.w - FogParam.z);
	fogValueHeight = clamp(fogValueHeight, 0.0, 1.0);
	float fogValueDist = (FogParam.y - dist)/(FogParam.y - FogParam.x);
	fogValueDist = clamp(fogValueDist, 0.0, 1.0);
	
	vertexTCoord1.x = fogValueDist;
	vertexTCoord1.y = fogValueHeight;
	
	vertexTCoord2 = ProjectPVBSMatrix_Dir * vec4(modelPosition, 1.0f);
}