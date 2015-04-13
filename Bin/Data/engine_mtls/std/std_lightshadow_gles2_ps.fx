varying mediump vec4 vertexColor;
varying mediump vec2 vertexTCoord0;
varying mediump vec2 vertexTCoord1;
varying mediump vec4 vertexTCoord2;
uniform mediump vec4 UVOffset;
uniform mediump vec4 FogColorHeight;
uniform mediump vec4 FogColorDist;
uniform sampler2D SampleBase;
uniform sampler2D SampleShadowDepth;

mediump float GetDepth(mediump vec4 texCord, mediump float i, mediump float j)
{
	mediump vec4 newUV = texCord + mediump vec4(texCord.w*i*0.001, texCord.w*j*0.001, 0.0, 0.0);
	mediump vec4 depthColor = texture2DProj(SampleShadowDepth, newUV);
				
	return depthColor.r;
}

void main()
{
	mediump vec2 texCoord = vec2(vertexTCoord0.x, 1.0-vertexTCoord0.y);
	texCoord.xy += UVOffset.xy;
	mediump vec4 lastColor = texture2D(SampleBase, texCoord);
	
	lastColor *= vertexColor;
	
	mediump vec4 texCord = vertexTCoord2;
	
	mediump float shadowDepth = GetDepth(texCord, 0.0, 0.0);
		
	lastColor.rgb *= shadowDepth;
	
	lastColor.rgb = lastColor.rgb * vertexTCoord1.x + FogColorHeight.rgb * (1.0 - vertexTCoord1.x);
	lastColor.rgb = lastColor.rgb * vertexTCoord1.y + FogColorDist.rgb * (1.0 - vertexTCoord1.y);
	
	gl_FragColor = lastColor;
}