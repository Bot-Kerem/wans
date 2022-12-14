#pragma once

#include <appbase.h>
#include <shader.h>
#include <mainviewport.h>
#include <topbar.h>
#include <widgeteditor.h>

class Editor: public AppBase
{
    private:
        static constexpr int initialWidth =  800;
        static constexpr int initialHeight = 800;

        Shader shader{"shaders/triangle.glsl", "shaders/fragment.glsl"};
        void setViewport(int w, int h);

        MainViewport m_MainViewport;
        WidgetEditor m_WidgetEditor;
    public:
        Editor();

        void render() override;
};
