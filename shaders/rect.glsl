#version 460 compatibility

vec2 rect[4] = vec2[](
    vec2(-1.0f,  1.0f),
    vec2(-1.0f, -1.0f),
    vec2( 1.0f,  1.0f),
    vec2( 1.0f, -1.0f)
);

void main()
{
    gl_Position = vec4(rect[gl_VertexID], 0.0f, 1.0f);
}
