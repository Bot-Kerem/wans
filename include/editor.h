#pragma once

#include <appbase.h>
#include <iostream>

class Editor: public AppBase
{
    private:
        void c(int x, int y)
        {
            std::cout << "X: " << x << " Y: " << y << '\n';
        }
    public:
        Editor();

        void render() override;
};
