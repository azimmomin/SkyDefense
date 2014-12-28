#include "AppDelegate.h"
#include "GameLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }

    CCSize screenSize = glview->getFrameSize();
    CCSize designSize = CCSize(2048, 1536);
    glview->setDesignResolutionSize(designSize.width, designSize.height, kResolutionExactFit);

    if (screenSize.height > 768) {
    	FileUtils::sharedFileUtils()->addSearchPath("ipadhd");
    } else if (screenSize.height > 320) {
    	FileUtils::sharedFileUtils()->addSearchPath("ipad");
    } else {
    	FileUtils::sharedFileUtils()->addSearchPath("iphone");
    }
    director->setContentScaleFactor(screenSize.height/designSize.height);
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("background.mp3");
    SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.4f);

    // create a scene. it's an autorelease object
    auto scene = GameLayer::scene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
