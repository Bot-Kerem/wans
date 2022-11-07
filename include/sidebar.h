#pragma once

#include <widget.h>

class SideBar: public Widget
{
    private:

    public:
        SideBar(float Width, float Height);
        void create_image() const noexcept override;
        void setSize(float Width, float Height) noexcept override;
};