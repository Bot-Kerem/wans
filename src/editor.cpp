#include <editor.h>

#include <glad/glad.h>

Editor::Editor(): AppBase{"Wans", 800, 1000}
{
    glClearColor(0,1,0,1);
    //m_Window.setFramebufferSizeCallback(c);
}

void Editor::render()
{
    glClear(GL_COLOR_BUFFER_BIT);
}
