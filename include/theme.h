#pragma once

#include <glm/vec3.hpp>
#include <array>

typedef glm::vec3 _Color;

enum ThemeCol_
{
    ThemeCol_Background = 0,
    ThemeCol_TopBar     = 1
};

class Theme
{
    private:
        _Color colors[2];
    public:
        Theme();

        _Color& operator[](ThemeCol_ index)
        {
            return colors[index];
        }
};
