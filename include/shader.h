#pragma once

#include <string>

#include <glad/glad.h>

class Shader
{
    private:
        unsigned int m_Program;
        void Compile(unsigned int Shader) const noexcept;
        void Link() const noexcept;
    public:
        Shader(std::string VertexShaderPath, std::string FragmentShaderPath) noexcept;

        inline void use() const noexcept
        {
            glUseProgram(m_Program);
        }
};

