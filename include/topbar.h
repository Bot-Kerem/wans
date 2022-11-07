#pragma once

#include <widget.h>

class TopBar: public Widget
{
    private:

    public:
        TopBar(float Width, float Height);
        void create_image() const noexcept override;
        void setSize(float Width, float Height) noexcept override;
};
