#include "AppDelegate.h"
#include "UserRule.h"
#include "TitleScene.h"
#include "GameManager.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{	}

AppDelegate::~AppDelegate()
{	
	GameManager::destroy();
}

void AppDelegate::initGLContextAttrs()
{
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };
	GLView::setGLContextAttrs(glContextAttrs);
}

static int register_all_packages()
{
	return 0;
}

bool AppDelegate::applicationDidFinishLaunching() 
{
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) 
	{
		glview = GLViewImpl::createWithRect("WatchOut", cocos2d::Rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
		director->setOpenGLView(glview);
	}
	director->setDisplayStats(true);
	director->setAnimationInterval(1.0f / 60);
	
//	glview->setFrameSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glview->setDesignResolutionSize(SCREEN_WIDTH, SCREEN_HEIGHT, ResolutionPolicy::SHOW_ALL);
	register_all_packages();

	auto scene = START_SCENE::createScene();
	director->runWithScene(scene);

	return true;
}

void AppDelegate::applicationDidEnterBackground() 
{
	Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground() 
{
	Director::getInstance()->startAnimation();
}