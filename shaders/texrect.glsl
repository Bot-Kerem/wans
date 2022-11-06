#version 460 compatibility

vec2 rect[4] = vec2[](
    vec2(-1.0f,  1.0f),
    vec2(-1.0f, -1.0f),
    vec2( 1.0f,  1.0f),
    vec2( 1.0f, -1.0f)
);

vec2 tex[4] = vec2[](
    vec2(0.0f, 1.0f),
    vec2(0.0f, 0.0f),
    vec2(1.0f, 1.0f),
    vec2(1.0f, 0.0f)
);

out vec2 TextureCoord;

void main()
{
    gl_Position = vec4(rect[gl_VertexID], 0.0f, 1.0f);
    TextureCoord = tex[gl_VertexID]
}
