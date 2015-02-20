// UI_gles2_ps.fx

varying mediump vec2 vertexTCoord0;
uniform sampler2D gDiffuseSampler;
void main()
{
	mediump vec2 tecCord = vec2(vertexTCoord0.x, 1.0-vertexTCoord0.y);
	gl_FragColor = texture2D(gDiffuseSampler, tecCord);
}