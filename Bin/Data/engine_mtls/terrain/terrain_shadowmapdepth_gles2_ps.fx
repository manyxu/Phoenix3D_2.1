varying mediump vec2 vertexTCoord0;
void main()
{
	gl_FragColor.rgb = vertexTCoord0.r;
	gl_FragColor.a = 1.0;
}