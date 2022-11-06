#pragma once

#include <framebuffer.h>
#include <memory>
#include <vector>

class Widget
{
    private:
        std::vector<Widget*> m_Childs;
        Widget* m_Parent;
    protected:
        std::unique_ptr<Framebuffer> m_Framebuffer;
        float m_Width;
        float m_Height;
    public:
        Widget(float Width, float Height) noexcept;
        void draw() noexcept;
        void update() noexcept;
        virtual void create_image() = 0;
};
