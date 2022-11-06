#include <theme.h>

Theme::Theme()
{
    colors[ThemeCol_Background] = _Color{0.156f, 0.172f, 0.2f};
    colors[ThemeCol_TopBar] = _Color{1.0f, 1.0f, 1.0f};
}

Theme theme{};
