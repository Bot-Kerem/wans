#pragma once

#include <widget.h>

class WidgetEditor
{
    //Widget& m_Widget;
    public:
        WidgetEditor(void* window) noexcept;
        //explicit WidgetEditor(Widget& widget, void* window) noexcept;
        ~WidgetEditor();
        void show();
};
