#pragma once

#include <widget.h>
#include <topbar.h>

class MainViewport: public Widget
{
    private:

    public:
        MainViewport(float Width, float Height);
        void create_image() const noexcept override;
        TopBar topBar;
};
