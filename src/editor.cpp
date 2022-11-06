#include <editor.h>

#include <glad/glad.h>

#include <functional>

#include <theme.h>
extern Theme theme;

void Editor::setViewport(int w, int h)
{
    glViewport(0, 0, w, h);
}


Editor::Editor(): AppBase{"Wans", 800, 800}
{
    glClearColor(theme[ThemeCol_Background].r, theme[ThemeCol_Background].g, theme[ThemeCol_Background].b, 1);
    m_Window.setFramebufferSizeCallback(std::bind(&Editor::setViewport, this, std::placeholders::_1, std::placeholders::_2));
}

void Editor::render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    shader.use();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
