#pragma once

#include <glad/glad.h>

class Framebuffer
{
    private:
        unsigned int m_Texture      = 0;
        unsigned int m_Framebuffer  = 0;
        unsigned int m_Renderbuffer = 0;
    public:
        Framebuffer(float Width, float Height) noexcept;
        ~Framebuffer() noexcept;

        void begin() const noexcept
        {
            glBindFramebuffer(GL_FRAMEBUFFER, m_Framebuffer);
        }

        void end() const noexcept
        {
            glBindFramebuffer(GL_FRAMEBUFFER, 0);
        }

        inline unsigned int getTexture() const noexcept
        {
            return m_Texture;
        }

        inline void setTexture() const noexcept
        {
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, m_Texture);
        }

        // Deleting copy assignment operator and copy constructor
        Framebuffer(const Framebuffer&) = delete;
        Framebuffer& operator = (const Framebuffer&) = delete;
};
