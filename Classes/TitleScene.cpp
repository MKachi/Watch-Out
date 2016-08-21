#include "TitleScene.h"

USING_NS_CC;

Scene* TitleScene::createScene()
{
	auto scene = Scene::create();

	auto layer = TitleScene::create();
	scene->addChild(layer);

	return scene;
}

bool TitleScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}