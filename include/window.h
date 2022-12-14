#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <functional>

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
            static void _CursorPosCallback(IWindow _Window, double Width, double Height) noexcept;

            std::function<void(int, int)> WindowSizeCallback;
            std::function<void(int, int)> FramebufferSizeCallback;
            std::function<void(double, double)> CursorPosCallback;
    public:
        Window(std::string Title, int Width, int Height);

        void pollEvents() noexcept;
        inline void swapBuffers() const noexcept {glfwSwapBuffers(m_Window);}

        // 
        inline int getWidth() const noexcept { return m_Width; }
        inline int getHeight() const noexcept { return m_Height; }
        inline IWindow getWindow() const noexcept { return m_Window; }
        inline int getViewportWidth() const noexcept { return m_ViewportWidth; }
        inline int getViewportHeight() const noexcept { return m_ViewportHeight; }
        inline int isClosed() const noexcept { return glfwWindowShouldClose(m_Window); }
        inline std::string getTitle() const noexcept { return m_Title; }

        // Callbacks
        void setFramebufferSizeCallback(std::function<void(int, int)> fn) noexcept;
        void setWindowSizeCallback(std::function<void(int, int)> fn) noexcept;
        void setCursorPosCallback(std::function<void(double, double)> fn) noexcept;

        // removing copy constructors
        Window(const Window&) = delete;
        Window operator=(const Window&) = delete;

};
