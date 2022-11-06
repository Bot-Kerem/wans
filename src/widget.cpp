#include <widget.h>

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
    m_Parent->update();
}
