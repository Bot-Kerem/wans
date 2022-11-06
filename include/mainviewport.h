#pragma once

#include <widget.h>

class MainViewport: public Widget
{
    private:
    public:
        MainViewport(float Width, float Height);
        void create_image() override;
};
