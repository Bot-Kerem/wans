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
    TextureShader->use();
    m_Framebuffer->setTexture();
    if(m_Parent)
    {
        TextureShader->setVec2("size", {static_cast<float>(m_Width)/static_cast<float>(m_Parent->m_Width), static_cast<float>(m_Height)/static_cast<float>(m_Parent->m_Height)});
        TextureShader->setVec2("pos", m_Position/glm::vec2{m_Parent->m_Width,m_Parent->m_Height});
        Renderer::SetViewport(m_Parent->m_Width, m_Parent->m_Height);
    }
    else
    {
        Renderer::SetViewport(m_Width, m_Height);
    }
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void Widget::update() noexcept
{
    // create_image();
    Renderer::SetViewport(m_Width, m_Height);
    m_Framebuffer->begin();
    create_image();
    for(Widget* widget: m_Childs)
    {
        widget->draw();
    }
    m_Framebuffer->end();
    if(m_Parent) m_Parent->update();
}
