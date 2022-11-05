#pragma once

#include <appbase.h>
#include <shader.h>

class Editor: public AppBase
{
    private:
        Shader shader{"shaders/triangle.glsl", "shaders/fragment.glsl"};
        void setViewport(int w, int h);
    public:
        Editor();

        void render() override;
};
