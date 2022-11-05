#pragma once

#include <window.h>
#include <theme.h>

class AppBase
{
    protected:
        Window m_Window;
        Theme theme{};

        virtual void render() = 0;
        AppBase(std::string Title, int Width, int Height);
    public:
        void run();
};
