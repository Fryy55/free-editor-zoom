#include <Geode/modify/EditorPauseLayer.hpp>

#include "QuickNotification.hpp"

using namespace geode::prelude;


class $modify(EditorPauseLayer) {
	$override
	bool init(LevelEditorLayer* lel) {
		if (!EditorPauseLayer::init(lel))
			return false;

		auto resetPosBtnSpr = ButtonSprite::create(
			"Reset\nPosition",
			30, true,
			"bigFont.fnt", "GJ_button_04.png",
			30, 1.f
		);
		resetPosBtnSpr->setScale(0.8f);
		auto resetPosBtn = CCMenuItemExt::createSpriteExtra(
			resetPosBtnSpr,
			[this](CCMenuItemSpriteExtra*) {
				m_editorLayer->m_editorUI->updateZoom(1.f);
				m_editorLayer->m_objectLayer->setPosition(0.f, 0.f);

				QuickNotification::create("Position reset", NotificationIcon::Success, 0.5f)->show();

				this->onResume(nullptr);
			}
		);
		resetPosBtn->setID("reset-position-button"_spr);

		auto menu = this->getChildByID("small-actions-menu");
		menu->addChild(resetPosBtn);
		menu->updateLayout();

		return true;
	}
};