#version 460 compatibility

vec2 rect[3] = vec2[](
    vec2(0.0f, 0.5f),
    vec2(0.5f, -0.5f),
    vec2(-0.5f, -0.5f)
);

void main()
{
    gl_Position = vec4(rect[gl_VertexID], 0.0f, 1.0f);
}
