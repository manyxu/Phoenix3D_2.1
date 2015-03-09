varying mediump vec4 vertexColor;
varying mediump vec2 vertexTCoord0;
varying mediump vec2 vertexTCoord1;
uniform sampler2D BaseSampler;
uniform mediump vec4 FogColor;
uniform mediump vec4 FogColorDist;
void main()
{
	mediump vec2 texCoord = vec2(vertexTCoord0.x, 1.0-vertexTCoord0.y);
	mediump vec4 lastColor = texture2D(BaseSampler, texCoord)*vertexColor;
	lastColor.rgb = lastColor.rgb * vertexTCoord1.y + FogColor.rgb * (1.0 - vertexTCoord1.y);
	lastColor.rgb = lastColor.rgb * vertexTCoord1.x + FogColorDist.rgb * (1.0 - vertexTCoord1.x);
	gl_FragColor = lastColor;
}