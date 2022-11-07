#include <topbar.h>
#include <theme.h>
extern Theme theme;

TopBar::TopBar(float Width, float Height)
    : Widget{Width, 25.0f/Height}
{

}

void TopBar::create_image() const noexcept
{
    RectShader->use();
    RectShader->setVec2("pos", glm::vec2(0.0f, 1.0f-m_Height));
    RectShader->setVec2("size", glm::vec2(1.0f, m_Height));
    RectShader->setVec3("color", theme[ThemeCol_TopBar]);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void TopBar::setSize(float Width, float Height) noexcept
{
    m_Height = 25.0f/Height;
}
