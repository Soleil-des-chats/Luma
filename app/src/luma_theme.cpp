//
//  luma_theme.cpp
//  Luma
//

#include "luma_theme.hpp"

#include <borealis.hpp>

namespace luma {

namespace {

using brls::Theme;

// Small helper so palettes stay readable.
void set(Theme& theme, const char* key, NVGcolor color) {
    theme.addColor(key, color);
}

void applyDarkPalette() {
    Theme& t = Theme::getDarkTheme();

    // Surfaces: deep blue-violet instead of flat grey.
    set(t, "brls/background", nvgRGB(18, 19, 27));
    set(t, "brls/backdrop", nvgRGBA(6, 7, 12, 190));
    set(t, "brls/text", nvgRGB(240, 241, 248));
    set(t, "brls/text_disabled", nvgRGB(102, 106, 124));
    set(t, "brls/accent", nvgRGB(166, 150, 255));
    set(t, "brls/click_pulse", nvgRGBA(166, 150, 255, 34));

    // Focus highlight: calm lavender -> rose gradient, no harsh white.
    set(t, "brls/highlight/background", nvgRGB(34, 36, 52));
    set(t, "brls/highlight/color1", nvgRGB(150, 132, 255));
    set(t, "brls/highlight/color2", nvgRGB(255, 154, 206));

    set(t, "brls/applet_frame/separator", nvgRGBA(255, 255, 255, 28));

    set(t, "brls/sidebar/background", nvgRGB(23, 24, 34));
    set(t, "brls/sidebar/active_item", nvgRGB(166, 150, 255));
    set(t, "brls/sidebar/separator", nvgRGB(42, 44, 60));

    set(t, "brls/header/border", nvgRGB(44, 46, 62));
    set(t, "brls/header/rectangle", nvgRGB(166, 150, 255));
    set(t, "brls/header/subtitle", nvgRGB(146, 150, 170));

    set(t, "brls/button/primary_enabled_background", nvgRGB(166, 150, 255));
    set(t, "brls/button/primary_disabled_background", nvgRGB(52, 54, 72));
    set(t, "brls/button/primary_enabled_text", nvgRGB(20, 18, 38));
    set(t, "brls/button/primary_disabled_text", nvgRGB(102, 106, 124));
    set(t, "brls/button/default_enabled_background", nvgRGB(36, 38, 54));
    set(t, "brls/button/default_disabled_background", nvgRGB(30, 32, 44));
    set(t, "brls/button/default_enabled_text", nvgRGB(240, 241, 248));
    set(t, "brls/button/default_disabled_text", nvgRGB(102, 106, 124));
    set(t, "brls/button/highlight_enabled_text", nvgRGB(166, 150, 255));
    set(t, "brls/button/highlight_disabled_text", nvgRGB(166, 150, 255));
    set(t, "brls/button/enabled_border_color", nvgRGBA(255, 255, 255, 40));
    set(t, "brls/button/disabled_border_color", nvgRGBA(255, 255, 255, 20));

    set(t, "brls/list/listItem_value_color", nvgRGB(190, 178, 255));

    set(t, "brls/slider/pointer_color", nvgRGB(245, 245, 252));
    set(t, "brls/slider/pointer_border_color", nvgRGB(166, 150, 255));
    set(t, "brls/slider/line_filled", nvgRGB(166, 150, 255));
    set(t, "brls/slider/line_empty", nvgRGB(62, 65, 86));

    set(t, "brls/spinner/bar_color", nvgRGBA(190, 178, 255, 90));

    set(t, "captioned_image/caption", nvgRGB(190, 178, 255));
}

void applyLightPalette() {
    Theme& t = Theme::getLightTheme();

    set(t, "brls/background", nvgRGB(245, 244, 250));
    set(t, "brls/backdrop", nvgRGBA(20, 18, 36, 150));
    set(t, "brls/text", nvgRGB(34, 32, 52));
    set(t, "brls/text_disabled", nvgRGB(150, 148, 168));
    set(t, "brls/accent", nvgRGB(104, 80, 228));
    set(t, "brls/click_pulse", nvgRGBA(104, 80, 228, 30));

    set(t, "brls/highlight/background", nvgRGB(255, 255, 255));
    set(t, "brls/highlight/color1", nvgRGB(118, 94, 240));
    set(t, "brls/highlight/color2", nvgRGB(244, 140, 192));

    set(t, "brls/applet_frame/separator", nvgRGBA(34, 32, 52, 36));

    set(t, "brls/sidebar/background", nvgRGB(255, 255, 255));
    set(t, "brls/sidebar/active_item", nvgRGB(104, 80, 228));
    set(t, "brls/sidebar/separator", nvgRGB(226, 224, 238));

    set(t, "brls/header/border", nvgRGB(224, 222, 236));
    set(t, "brls/header/rectangle", nvgRGB(104, 80, 228));
    set(t, "brls/header/subtitle", nvgRGB(120, 118, 140));

    set(t, "brls/button/primary_enabled_background", nvgRGB(104, 80, 228));
    set(t, "brls/button/primary_disabled_background", nvgRGB(214, 212, 228));
    set(t, "brls/button/primary_enabled_text", nvgRGB(255, 255, 255));
    set(t, "brls/button/primary_disabled_text", nvgRGB(170, 168, 188));
    set(t, "brls/button/default_enabled_background", nvgRGB(255, 255, 255));
    set(t, "brls/button/default_disabled_background", nvgRGB(250, 249, 253));
    set(t, "brls/button/default_enabled_text", nvgRGB(34, 32, 52));
    set(t, "brls/button/default_disabled_text", nvgRGB(150, 148, 168));
    set(t, "brls/button/highlight_enabled_text", nvgRGB(104, 80, 228));
    set(t, "brls/button/highlight_disabled_text", nvgRGB(104, 80, 228));
    set(t, "brls/button/enabled_border_color", nvgRGBA(34, 32, 52, 36));
    set(t, "brls/button/disabled_border_color", nvgRGBA(34, 32, 52, 20));

    set(t, "brls/list/listItem_value_color", nvgRGB(104, 80, 228));

    set(t, "brls/slider/pointer_color", nvgRGB(255, 255, 255));
    set(t, "brls/slider/pointer_border_color", nvgRGB(104, 80, 228));
    set(t, "brls/slider/line_filled", nvgRGB(104, 80, 228));
    set(t, "brls/slider/line_empty", nvgRGB(210, 208, 226));

    set(t, "brls/spinner/bar_color", nvgRGBA(104, 80, 228, 80));

    set(t, "captioned_image/caption", nvgRGB(104, 80, 228));
}

void applyStyle() {
    auto style = brls::getStyle();

    // Softer, calmer focus ring instead of the thick console-style outline.
    style.addMetric("brls/highlight/stroke_width", 3.0f);
    style.addMetric("brls/highlight/corner_radius", 14.0f);
    style.addMetric("brls/highlight/shadow_width", 1.0f);
    style.addMetric("brls/highlight/shadow_offset", 6.0f);
    style.addMetric("brls/highlight/shadow_feather", 18.0f);
    style.addMetric("brls/highlight/shadow_opacity", 70.0f);
    style.addMetric("brls/animations/highlight", 160.0f);
    style.addMetric("brls/animations/highlight_shake", 8.0f);

    // Slimmer chrome: the header and footer used to eat a lot of screen,
    // which hurts on phones held in landscape.
    style.addMetric("brls/applet_frame/header_height", 76.0f);
    style.addMetric("brls/applet_frame/header_padding_top_bottom", 12.0f);
    style.addMetric("brls/applet_frame/header_padding_sides", 28.0f);
    style.addMetric("brls/applet_frame/header_title_font_size", 26.0f);
    style.addMetric("brls/applet_frame/footer_height", 56.0f);
    style.addMetric("brls/applet_frame/footer_padding_top_bottom", 14.0f);
    style.addMetric("brls/applet_frame/footer_padding_sides", 22.0f);
    style.addMetric("brls/applet_frame/padding_sides", 22.0f);

    // Sidebar: narrower, with big comfortable touch rows.
    style.addMetric("brls/tab_frame/sidebar_width", 330.0f);
    style.addMetric("brls/sidebar/padding_left", 28.0f);
    style.addMetric("brls/sidebar/padding_right", 28.0f);
    style.addMetric("brls/sidebar/padding_top", 20.0f);
    style.addMetric("brls/sidebar/padding_bottom", 24.0f);
    style.addMetric("brls/sidebar/item_height", 64.0f);
    style.addMetric("brls/sidebar/item_font_size", 21.0f);
    style.addMetric("brls/sidebar/item_accent_rect_width", 4.0f);
    style.addMetric("brls/sidebar/separator_height", 18.0f);
    style.addMetric("brls/sidebar/border_height", 8.0f);

    // Content area.
    style.addMetric("brls/tab_details/padding_top", 24.0f);
    style.addMetric("brls/tab_details/padding_bottom", 32.0f);
    style.addMetric("brls/tab_details/padding_left", 36.0f);
    style.addMetric("brls/tab_details/padding_right", 44.0f);

    // Typography: a touch larger for readability.
    style.addMetric("brls/label/default_font_size", 20.0f);
    style.addMetric("brls/label/default_line_height", 1.55f);
    style.addMetric("brls/header/font_size", 17.0f);
    style.addMetric("brls/header/rectangle_width", 4.0f);
    style.addMetric("brls/header/rectangle_height", 26.0f);

    // Buttons: rounder, with finger-sized padding.
    style.addMetric("brls/button/corner_radius", 14.0f);
    style.addMetric("brls/button/padding_top_bottom", 17.0f);
    style.addMetric("brls/button/padding_sides", 28.0f);
    style.addMetric("brls/button/text_size", 19.0f);
    style.addMetric("brls/button/border_thickness", 1.0f);

    // Lists and dropdowns.
    style.addMetric("brls/listitem/selectRadius", 14.0f);
    style.addMetric("brls/listitem/indent", 32.0f);
    style.addMetric("brls/dropdown/listItemHeight", 64.0f);
    style.addMetric("brls/dropdown/listItemTextSize", 21.0f);
    style.addMetric("brls/dropdown/listPaddingSides", 120.0f);
    style.addMetric("brls/dropdown/listPadding", 28.0f);
    style.addMetric("brls/dropdown/header_height", 64.0f);

    // Dialogs and notifications: less padding so they fit small screens.
    style.addMetric("brls/dialog/paddingTopBottom", 40.0f);
    style.addMetric("brls/dialog/paddingLeftRight", 56.0f);
    style.addMetric("brls/dialog/fontSize", 22.0f);
    style.addMetric("brls/notification/width", 320.0f);

    // Gentler shadows.
    style.addMetric("brls/shadow/opacity", 40.0f);
    style.addMetric("brls/shadow/feather", 18.0f);

    // Motion: slightly quicker so navigation feels fluid.
    style.addMetric("brls/animations/show", 160.0f);
    style.addMetric("brls/animations/show_slide", 100.0f);

    // Luma-specific metrics used by the About tab.
    style.addMetric("about/padding_top_bottom", 32.0f);
    style.addMetric("about/padding_sides", 48.0f);
    style.addMetric("about/description_margin", 32.0f);
}

} // namespace

void configureViewport() {
#if defined(PLATFORM_IOS) || defined(PLATFORM_ANDROID)
    // Borealis lays everything out for a 1280x720 canvas and scales it to the
    // window. On a phone that makes text tiny. A smaller base canvas means a
    // larger scale factor, so text and touch targets grow by about a third.
    brls::Application::ORIGINAL_WINDOW_WIDTH = 960;
    brls::Application::ORIGINAL_WINDOW_HEIGHT = 540;
#endif
}

void applyTheme() {
    applyDarkPalette();
    applyLightPalette();
    applyStyle();
}

} // namespace luma
