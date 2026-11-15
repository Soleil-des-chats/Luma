//
//  luma_theme.hpp
//  Luma
//
//  Visual identity of Luma: a softer, rounder, touch-friendly look that is
//  applied on top of the stock Borealis theme without changing the layout.
//

#pragma once

namespace luma {

/// Applies the Luma colour palette (light + dark) and the style metrics.
/// Must be called after brls::Application::init() and before any view is built.
void applyTheme();

/// Adapts the base UI resolution so the interface is comfortable on phones
/// and tablets. Must be called after brls::Application::init() and before
/// brls::Application::createWindow().
void configureViewport();

} // namespace luma
