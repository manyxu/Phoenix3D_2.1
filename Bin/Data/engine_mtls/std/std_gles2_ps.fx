varying mediump vec4 vertexColor;
varying mediump vec2 vertexTCoord0;
varying mediump vec2 vertexTCoord1;
varying mediump vec4 vertexTCoord2;
uniform mediump vec4 FogColorHeight;
uniform mediump vec4 FogColorDist;
uniform sampler2D SampleBase;
uniform sampler2D SampleShadowDepth;
void main()
{
	mediump vec2 texCoord = vec2(vertexTCoord0.x, 1.0-vertexTCoord0.y);
	mediump vec4 lastColor = texture2D(SampleBase, texCoord);
	
	lastColor *= vertexColor;
	
	mediump vec4 texCord = vertexTCoord2;
	
	mediump float depth = texCord.z/texCord.w;
	mediump vec4 depthColor = texture2DProj(SampleShadowDepth, texCord);
	mediump float depthVal = depthColor.x*255+depthColor.y;
	
	mediump float lightAmout = 1.0;
	if (depth > depthVal) lightAmout = 0.0;
	lastColor.rgb *= lightAmout;
	
	lastColor.rgb = lastColor.rgb * vertexTCoord1.y + FogColorHeight.rgb * (1.0 - vertexTCoord1.y);
	lastColor.rgb = lastColor.rgb * vertexTCoord1.x + FogColorDist.rgb * (1.0 - vertexTCoord1.x);
	
	gl_FragColor = lastColor;
}