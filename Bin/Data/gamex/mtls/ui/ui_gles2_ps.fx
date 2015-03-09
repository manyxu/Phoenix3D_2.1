uniform vec4 UVParam;
uniform vec4 ShineEmissive;
varying mediump vec2 vertexTCoord0;
uniform sampler2D gDiffuseSampler;
void main()
{
	mediump vec2 texCord = vec2(vertexTCoord0.x, 1.0-vertexTCoord0.y)*UVParam.xy;
	mediump vec4 color = texture2D(gDiffuseSampler, texCord);
	gl_FragColor = color*ShineEmissive;
}