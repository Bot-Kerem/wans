#pragma once

#include <appbase.h>
#include <shader.h>
#include <mainviewport.h>

class Editor: public AppBase
{
    private:
        static constexpr int initialWidth =  800;
        static constexpr int initialHeight = 800;

        Shader shader{"shaders/triangle.glsl", "shaders/fragment.glsl"};
        void setViewport(int w, int h);

        MainViewport m_MainViewport;
    public:
        Editor();

        void render() override;
};
