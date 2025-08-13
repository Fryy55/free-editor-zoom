#include <Geode/modify/EditorUI.hpp>


class $modify(HEditorUI, EditorUI) {
	struct Fields {
		float m_zoomFactor;
		float m_zoomMin;
		float m_zoomMax;

		bool m_uiToggle;


		cocos2d::CCLabelBMFont* m_zoomLabel;
	};


    $override
	bool init(LevelEditorLayer* lel);

    $override
	void updateZoom(float zoom);



	//* reimplementations woo
	static void onModify(auto& self);

    $override
	void zoomIn(CCObject*);

    $override
	void zoomOut(CCObject*);

    $override
	void scrollWheel(float p0, float p1);
};