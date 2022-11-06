#include <window.h>

#ifndef GL_VERSION_MAJOR
    #define GL_VERSION_MAJOR 4
#endif
#ifndef GL_VERSION_MINOR
    #define GL_VERSION_MINOR 6
#endif
#ifndef GL_PROFILE
    #define GL_PROFILE GLFW_OPENGL_COMPAT_PROFILE
#endif

Window::Window(std::string Title, int Width, int Height)
    : m_Title{Title}, m_Width{Width}, m_Height{Height}
{
    // Initializing GLFW
    glfwInit();

    // Setting OpenGL Context Version 4.6
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_VERSION_MAJOR);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_VERSION_MINOR);
    // Setting OpenGL profile to compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GL_PROFILE);

    m_Window = glfwCreateWindow(Width, Height, Title.c_str(), nullptr, nullptr);

    glfwMakeContextCurrent(m_Window);
    
    gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress));

    glfwSetWindowUserPointer(m_Window, this);
}

void Window::pollEvents() noexcept
{
    //glfwPollEvents();
    glfwWaitEvents();
    glfwGetWindowSize(m_Window, &m_Width, &m_Height);
    glfwGetCursorPos(m_Window, &m_MousePosX, &m_MousePosY);
}

void Window::setFramebufferSizeCallback(std::function<void(int, int)> fn) noexcept
{
    glfwSetFramebufferSizeCallback(m_Window, _FramebufferSizeCallback);
    FramebufferSizeCallback = fn;
}

void Window::setWindowSizeCallback(std::function<void(int, int)> fn) noexcept
{
    glfwSetWindowSizeCallback(m_Window, _WindowSizeCallback);
    WindowSizeCallback = fn;
}

void Window::setCursorPosCallback(std::function<void(double, double)> fn) noexcept
{
    glfwSetCursorPosCallback(m_Window, _CursorPosCallback);
    WindowSizeCallback = fn;
}

void Window::_FramebufferSizeCallback(IWindow _Window, int Width, int Height) noexcept
{
    auto window = static_cast<Window*>(glfwGetWindowUserPointer(_Window));

    if(window->FramebufferSizeCallback)
    {
        window->FramebufferSizeCallback(Width, Height);
    }
}

void Window::_WindowSizeCallback(IWindow _Window, int Width, int Height) noexcept
{
    auto window = static_cast<Window*>(glfwGetWindowUserPointer(_Window));

    if(window->WindowSizeCallback)
    {
        window->WindowSizeCallback(Width, Height);
    }
}

void Window::_CursorPosCallback(IWindow _Window, double Width, double Height) noexcept
{
    auto window = static_cast<Window*>(glfwGetWindowUserPointer(_Window));

    if(window->CursorPosCallback)
    {
        window->CursorPosCallback(Width, Height);
    }
}

