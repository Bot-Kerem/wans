#include <shader.h>
#include <platform.h>

#include <iostream>

Shader::Shader(std::string VertexShaderPath, std::string FragmentShaderPath) noexcept
{
    m_Program = glCreateProgram();

    unsigned int VertexShader = glCreateShader(GL_VERTEX_SHADER);
    {
        std::string VertexShaderSource = Platform::OpenFile(VertexShaderPath);
        const char* sourceCode = &VertexShaderSource[0];
        glShaderSource(VertexShader, 1, &sourceCode, 0);
        Compile(VertexShader);
    }

    unsigned int FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    {
        std::string FragmentShaderSource = Platform::OpenFile(FragmentShaderPath);
        const char* sourceCode = &FragmentShaderSource[0];
        glShaderSource(FragmentShader, 1, &sourceCode, 0);
        Compile(FragmentShader);
    }

    glAttachShader(m_Program, VertexShader);
    glAttachShader(m_Program, FragmentShader);

    Link();

    glDeleteShader(VertexShader);
    glDeleteShader(FragmentShader);
}

void Shader::Compile(unsigned int Shader) const noexcept
{
    glCompileShader(Shader);
    int isCompiled = 0;
    glGetShaderiv(Shader, GL_COMPILE_STATUS, &isCompiled);
    if(!isCompiled)
    {
        char log[512];
        glGetShaderInfoLog(Shader, 512, 0, log);
        std::cout << log;
    }
}

void Shader::Link() const noexcept
{
    glLinkProgram(m_Program);
    int isLinked = 0;
    glGetProgramiv(m_Program, GL_LINK_STATUS, &isLinked);
    if(!isLinked)
    {
        char log[512];
        glGetProgramInfoLog(m_Program, 512, 0, log);
        std::cout << log;
    }
}
