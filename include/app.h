#pragma once

#include <window.h>

class App
{
    protected:
        Window m_Window;

        virtual void render() = 0;
        App(std::string Title, int Width, int Height):m_Window{Title, Width, Height} {}
    public:
        void run();
};
