#include <editor.h>
#include <theme.h>
#include <renderer.h>
extern Theme theme;

#include <glad/glad.h>

#include <functional>

void Editor::setViewport(int w, int h)
{
    glViewport(0, 0, w, h);
    m_MainViewport.setSize(w, h);
    Renderer::SetViewport(w, h);
}


Editor::Editor()
    : AppBase{"Wans", initialWidth, initialHeight}, m_MainViewport{initialWidth, initialHeight}
{
    glClearColor(theme[ThemeCol_Background].r, theme[ThemeCol_Background].g, theme[ThemeCol_Background].b, 1);
    m_Window.setFramebufferSizeCallback(std::bind(&Editor::setViewport, this, std::placeholders::_1, std::placeholders::_2));
}

void Editor::render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    m_MainViewport.draw();
    //m_TopBar.draw();
    shader.use();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
