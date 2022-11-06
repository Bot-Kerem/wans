#pragma once

#include <string>

#include <glad/glad.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

class Shader
{
    private:
        unsigned int m_Program;
        void Compile(unsigned int Shader) const noexcept;
        void Link() const noexcept;
        inline int getUniformLocation(const char* name) const noexcept { return glGetUniformLocation(m_Program, name); }
    public:
        Shader(std::string VertexShaderPath, std::string FragmentShaderPath) noexcept;

        inline void setVec2(const char* name, const glm::vec2& val) const noexcept { glUniform2f(getUniformLocation(name), val.x, val.y); }
        inline void setVec3(const char* name, const glm::vec3& val) const noexcept { glUniform3f(getUniformLocation(name), val.x, val.y, val.z); }
        inline void setVec4(const char* name, const glm::vec4& val) const noexcept { glUniform4f(getUniformLocation(name), val.r, val.g, val.b, val.a); }

        inline void use() const noexcept
        {
            glUseProgram(m_Program);
        }
};

