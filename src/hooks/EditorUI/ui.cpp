#include "EditorUI.hpp"

using namespace geode::prelude;


$override
bool HEditorUI::init(LevelEditorLayer* lel) {
	if (!EditorUI::init(lel))
		return false;

	// settings setup
	m_fields->m_zoomFactor = Mod::get()->getSettingValue<float>("zoom-factor");
	m_fields->m_zoomMin = Mod::get()->getSettingValue<float>("zoom-min");
	m_fields->m_zoomMax = Mod::get()->getSettingValue<float>("zoom-max");

	m_fields->m_uiToggle = Mod::get()->getSettingValue<bool>("ui-toggle");



	if (!m_fields->m_uiToggle)
		return true;

	auto zoomLabel = CCLabelBMFont::create("", "bigFont.fnt");
	auto undoMenu = m_undoBtn->getParent();

	zoomLabel->setPosition(
		undoMenu->getPositionX() - 57.f,
		undoMenu->getPositionY() - undoMenu->getContentHeight() / 2.f
	);
	zoomLabel->setAnchorPoint({ 0.f, 1.f });	
	zoomLabel->setScale(0.65f);
	zoomLabel->setOpacity(0);
	zoomLabel->setID("zoom-label"_spr);
	this->addChild(zoomLabel);

	m_fields->m_zoomLabel = zoomLabel;

	return true;
}

$override
void HEditorUI::updateZoom(float zoom) {
	EditorUI::updateZoom(zoom);

	if (!m_fields->m_uiToggle)
		return;

	auto zoomLabel = m_fields->m_zoomLabel;

	zoomLabel->setString(fmt::format("Zoom: x{}", numToString(zoom, 2)).c_str());

	zoomLabel->stopAllActions();
	zoomLabel->setOpacity(255);
	zoomLabel->runAction(
		CCSequence::createWithTwoActions(
			CCDelayTime::create(0.3f),
			CCFadeTo::create(0.7f, 0)
		)
	);

	return;
}