#include <Geode/Geode.hpp>
#include "Geode/modify/MenuLayer.hpp"
#include <Geode/ui/Popup.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
public:
    bool init() {
        if (!MenuLayer::init()) return false;

        auto menu = this->getChildByID("main-menu");
        if (menu) {
            auto generateBtn = CCMenuItemFont::create("Generate Level", this, menu_selector(MenuLayer::onGenerateLevel));
            generateBtn->setPosition({0, -100});
            menu->addChild(generateBtn);
        }

        return true;
    }

    void onGenerateLevel(CCObject*) {
        FLAlertLayer::create("Level Generator", "Enter a prompt for your level:", "Cancel", "Generate", this)->show();
    }

    void FLAlert_Clicked(FLAlertLayer*, bool btn2) {
        if (btn2) {
            // TODO: Implement level generation logic here
            FLAlertLayer::create("Success", "Level generated successfully!", "OK")->show();
        }
    }
};
