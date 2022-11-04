#include <app.h>

void App::run()
{
    while (!m_Window.isClosed())
    {
        m_Window.pollEvents();
    }
}
