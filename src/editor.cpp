#include <editor.h>

#include <glad/glad.h>

Editor::Editor(): App{"Wans", 800, 1000}
{
    glClearColor(0,1,0,1);
}

void Editor::render()
{
    glClear(GL_COLOR_BUFFER_BIT);
}
