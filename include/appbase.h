#pragma once

#include <window.h>

class AppBase
{
    protected:
        Window m_Window;

        virtual void render() = 0;
        AppBase(std::string Title, int Width, int Height);
    public:
        void run();
};
