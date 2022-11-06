#include <mainviewport.h>

#include <renderer.h>
#include <theme.h>
extern Theme theme;

MainViewport::MainViewport(float Width, float Height): Widget(Width, Height)
{

}

void MainViewport::create_image()
{
    Renderer::SetViewport(m_Width, m_Height);
    m_Framebuffer->begin();
    Renderer::Clear(theme[ThemeCol_TopBar]);
    m_Framebuffer->end();
}
