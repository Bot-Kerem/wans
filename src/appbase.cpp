#include <appbase.h>

AppBase::AppBase(std::string Title, int Width, int Height)
    : m_Window{Title, Width, Height}
{

}

void AppBase::run()
{
    while (!m_Window.isClosed())
    {
        m_Window.pollEvents();

        render();
        
        m_Window.swapBuffers();
    }
}
