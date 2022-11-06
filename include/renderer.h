#pragma once

#include <glad/glad.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

namespace Renderer
{
    inline void SetClearColor(float r, float g, float b, float a) noexcept
    {
        glClearColor(r, g, b, a);
    }

    inline void Clear() noexcept
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    inline void Clear(glm::vec3 Color, float Alpha = 1.0f) noexcept
    {
        SetClearColor(Color.r, Color.g, Color.b, Alpha);
        Clear();
    }

    inline void Clear(glm::vec4 Color) noexcept
    {
        SetClearColor(Color.r, Color.g, Color.b, Color.a);
        Clear();
    }

    inline void SetViewport(int Width, int Height) noexcept
    {
        glViewport(0, 0, Width, Height);
    }
    
    inline void SetViewport(glm::ivec2 size) noexcept
    {
        glViewport(0, 0, size.x, size.y);
    }
} // namespace Renderer
