#include "about_tab.hpp"
#include <fmt/core.h>

#include <utility>

#ifdef __SWITCH__
#include <switch.h>
#endif

using namespace brls;

void openWebpage(std::string url) {
    Application::getPlatform()->openBrowser(std::move(url));
}

AboutTab::AboutTab() {
    this->inflateFromXMLRes("xml/tabs/about.xml");

    ThemeVariant variant = Application::getThemeVariant();
    std::string themePart =
        variant == brls::ThemeVariant::DARK ? "_dark" : "_light";

    std::string subtitle = fmt::format(fmt::runtime("about/version"_i18n), APP_VERSION);
    versionLabel->setSubtitle(subtitle);

    std::string githubLink = "https://github.com/Soleil-des-chats/Luma";
    github->addGestureRecognizer(new TapGestureRecognizer(github));
    github->title->setText("about/link_github"_i18n);
    github->subtitle->setText(githubLink);
    github->image->setImageFromRes("img/links/github" + themePart + ".png");
    github->registerClickAction([githubLink](View* view) {
        openWebpage(githubLink);
        return true;
    });

    std::string originalLink = "https://github.com/XITRIX/Moonlight-Switch";
    patreon->addGestureRecognizer(new TapGestureRecognizer(patreon));
    patreon->title->setText("about/link_patreon"_i18n);
    patreon->subtitle->setText(originalLink);
    patreon->image->setImageFromRes("img/links/github" + themePart + ".png");
    patreon->registerClickAction([originalLink](View* view) {
        openWebpage(originalLink);
        return true;
    });

    std::string moonlightLink = "https://moonlight-stream.org";
    gbatemp->addGestureRecognizer(new TapGestureRecognizer(gbatemp));
    gbatemp->title->setText("about/link_gbatemp"_i18n);
    gbatemp->subtitle->setText(moonlightLink);
    gbatemp->image->setImageFromRes("img/moonlight_96.png");
    gbatemp->registerClickAction([moonlightLink](View* view) {
        openWebpage(moonlightLink);
        return true;
    });
}

brls::View* AboutTab::create() { return new AboutTab(); }
