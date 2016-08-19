#include "AppDelegate.h"
#include "UserRule.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{	}

AppDelegate::~AppDelegate() 
{	}

void AppDelegate::initGLContextAttrs()
{
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
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
    if(!glview) 
	{
		glview = GLViewImpl::create(GAME_TITLE);
        director->setOpenGLView(glview);
    }

	glview->setFrameSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glview->setDesignResolutionSize(SCREEN_WIDTH, SCREEN_HEIGHT, ResolutionPolicy::SHOW_ALL);

    director->setDisplayStats(SHOW_FPS);
    director->setAnimationInterval(1.0f / 60);
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