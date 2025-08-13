#include "EditorUI.hpp"

using namespace geode::prelude;


void HEditorUI::onModify(auto& self) {
	if (!self.setHookPriorityPre("EditorUI::zoomIn", Priority::Replace))
		log::warn("Failed to set hook priority for EditorUI::zoomIn");

	if (!self.setHookPriorityPre("EditorUI::zoomOut", Priority::Replace))
		log::warn("Failed to set hook priority for EditorUI::zoomOut");

	if (!self.setHookPriorityPre("EditorUI::scrollWheel", Priority::Replace))
		log::warn("Failed to set hook priority for EditorUI::scrollWheel");


	return;
}

$override
void HEditorUI::zoomIn(CCObject*) {
	float zoom = m_editorLayer->m_objectLayer->getScale();

	zoom += zoom * m_fields->m_zoomFactor;
	zoom = std::clamp(zoom, m_fields->m_zoomMin, m_fields->m_zoomMax);

	this->updateZoom(zoom);

	return;
}

$override
void HEditorUI::zoomOut(CCObject*) {
	float zoom = m_editorLayer->m_objectLayer->getScale();

	zoom -= zoom * m_fields->m_zoomFactor;
	zoom = std::clamp(zoom, m_fields->m_zoomMin, m_fields->m_zoomMax);

	this->updateZoom(zoom);

	return;
}

$override
void HEditorUI::scrollWheel(float p0, float p1) {
	if (CCKeyboardDispatcher::get()->getControlKeyPressed()) {
		if (p0 < 0)
			this->zoomIn(nullptr);
		else
			this->zoomOut(nullptr);
	} else {
		EditorUI::scrollWheel(p0, p1);
	}

	return;
}