#include "CmTestTextSprite.h"
#include "CmSceneObject.h"
#include "BsRenderable.h"
#include "CmMesh.h"
#include "CmVector2.h"
#include "BsTextSprite.h"
#include "CmFont.h"
#include "CmMaterial.h"
#include "BsGUILabel.h"
#include "BsGUIWindowFrame.h"
#include "BsGUISkin.h"
#include "BsOverlayManager.h"
#include "BsSpriteTexture.h"
#include "BsEngineGUI.h"

using namespace BansheeEngine;

namespace CamelotFramework
{
	TestTextSprite::TestTextSprite(const HSceneObject& parent)
		:GUIWidget(parent)
	{
	}

	TestTextSprite::~TestTextSprite()
	{
	}

	void TestTextSprite::init(const HCamera& camera, const String& text, const HTexture& windowFrameTex)
	{
		OverlayManager::instance().attachOverlay(camera.get(), this);		

		setSkin(&EngineGUI::instance().getSkin());
		GUILabel::create(this, text, 400, 400, true, THA_Right, TVA_Bottom);

		SpriteTexturePtr frameSpriteTex(CM_NEW(SpriteTexture, PoolAlloc) SpriteTexture(windowFrameTex), &MemAllocDeleter<SpriteTexture, PoolAlloc>::deleter);
		GUIWindowFrame::create(this, frameSpriteTex);
	}

	void TestTextSprite::update()
	{

	}
}