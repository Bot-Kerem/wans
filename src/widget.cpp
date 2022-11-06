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
    m_Framebuffer = std::make_unique<Framebuffer>(m_Width, m_Height);
}

void Widget::draw() noexcept
{
    Renderer::SetViewport(m_Width, m_Height);
    TextureShader->use();
    m_Framebuffer->setTexture();
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
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
    create_image();
    m_Framebuffer->end();

    if(m_Parent) m_Parent->update();
}
