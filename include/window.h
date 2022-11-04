#pragma once

#include <GLFW/glfw3.h>
#include <string>

typedef GLFWwindow* IWindow;

class Window
{
    private:
            std::string m_Title = 0;
            int m_Width = 0;
            int m_Height = 0;
            int m_ViewportWidth = 0;
            int m_ViewportHeight = 0;
            double m_MousePosX = 0;
            double m_MousePosY = 0;

            IWindow m_Window;

            static void _FramebufferSizeCallback(IWindow _Window, int Width, int Height) noexcept;
            static void _WindowSizeCallback(IWindow _Window, int Width, int Height) noexcept;

            void (*FramebufferSizeCallback)(int, int) = nullptr;
            void (*WindowSizeCallback)(int, int) = nullptr;
    public:
        Window(std::string Title, int Width, int Height);

        void pollEvents() noexcept;

        // 
        inline int getWidth() const noexcept { return m_Width; }
        inline int getHeight() const noexcept { return m_Height; }
        inline IWindow getWindow() const noexcept { return m_Window; }
        inline int getViewportWidth() const noexcept { return m_ViewportWidth; }
        inline int getViewportHeight() const noexcept { return m_ViewportHeight; }
        inline int isClosed() const noexcept { return glfwWindowShouldClose(m_Window); }
        inline std::string getTitle() const noexcept { return m_Title; }

        // Callbacks
        void setFramebufferSizeCallback(void (*fn)(int, int)) noexcept;
        void setWindowSizeCallback(void (*fn)(int, int)) noexcept;

        // removing copy constructors
        Window(const Window&) = delete;
        Window operator=(const Window&) = delete;

};