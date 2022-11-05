#include <editor.h>

#include <glad/glad.h>

#include <functional>

Editor::Editor(): AppBase{"Wans", 800, 1000}
{
    glClearColor(theme[ThemeCol_Background].r, theme[ThemeCol_Background].g, theme[ThemeCol_Background].b, 1);
    //m_Window.setFramebufferSizeCallback(std::bind(&Editor::c, this, std::placeholders::_1, std::placeholders::_2));
}

void Editor::render()
{
    glClear(GL_COLOR_BUFFER_BIT);
}
