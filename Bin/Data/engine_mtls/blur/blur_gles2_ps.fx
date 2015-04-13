varying mediump vec2 vertexTCoord0;
uniform mediump vec4 UVParam;
uniform mediump vec4 ShineEmissive;
uniform mediump vec4 UVOffsets[16];
uniform sampler2D SamplerBase;
void main()
{
	mediump vec2 uv = mediump vec2(vertexTCoord0.x, 1.0-vertexTCoord0.y)*UVParam.xy;
	
	mediump vec2 uvSample = mediump vec2(0.0, 0.0);
	mediump vec4 sampleColor = mediump vec4(0.0, 0.0, 0.0, 0.0);
	mediump vec4 lastColor = mediump vec4(0.0, 0.0, 0.0, 0.0);
	for (int i = 0; i < 15; i++)
    {
        uvSample = uv + UVOffsets[i].xy;
        sampleColor = texture2D(SamplerBase, uvSample);
        lastColor += sampleColor * UVOffsets[i].z;
    }
	gl_FragColor = lastColor*ShineEmissive;
}