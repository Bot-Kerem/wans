#pragma once

#include <framebuffer.h>
#include <shader.h>
#include <memory>
#include <vector>
#include <glm/vec2.hpp>

class Widget
{
    private:
        std::vector<Widget*> m_Childs;
        Widget* m_Parent;
    protected:
        std::unique_ptr<Framebuffer> m_Framebuffer;
        float m_Width;
        float m_Height;
        glm::vec2 m_Position{0.0f};

        inline static Shader* RectShader = nullptr;
        inline static Shader* TextureShader = nullptr;
    public:
        inline void addChild(Widget* widget) noexcept
        {
            m_Childs.push_back(widget);
            widget->m_Parent = this;
        }
        virtual void setSize(float Width, float Height) noexcept
        {
            m_Width = Width;
            m_Height = Height;
            for(Widget* widget: m_Childs)
            {
                widget->setSize(Width, Height);
            }
            update();
        }
        static void init() noexcept;
        static void destroy() noexcept;
        Widget(float Width, float Height) noexcept;
        void draw() noexcept;
        void update() noexcept;
        virtual void create_image() const noexcept = 0;

        friend class WidgetEditor;
};
