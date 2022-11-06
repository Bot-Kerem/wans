#include <widget.h>
#include <renderer.h>

void Widget::init() noexcept
{
    RectShader = new Shader{"shaders/rect.glsl", "shaders/fragment.glsl"};
    TextureShader = new Shader{"shaders/texrect.glsl", "shaders/texture.glsl"};
}

void Widget::destroy() noexcept
{
    delete RectShader;
    delete TextureShader;
}

Widget::Widget(float Width, float Height) noexcept
    : m_Width{Width}, m_Height{Height}
{
    m_Framebuffer = std::make_unique<Framebuffer>(Framebuffer(m_Width, m_Height));
}

void Widget::draw() noexcept
{
    // pass
}

void Widget::update() noexcept
{
    // create_image();
    for(Widget* widget: m_Childs)
    {
        widget->draw();
    }

    Renderer::SetViewport(m_Width, m_Height);
    m_Framebuffer->begin();
    this->draw();
    m_Framebuffer->end();

    m_Parent->update();
}
