#include <mainviewport.h>

#include <renderer.h>
#include <theme.h>
extern Theme theme;

MainViewport::MainViewport(float Width, float Height): Widget(Width, Height)
{

}

void MainViewport::create_image()
{
    Renderer::Clear(theme[ThemeCol_TopBar]);
}
