#include "AppDelegate.h"
#include "WelcomeScene.h"

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(360, 640);
//static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
//static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
//static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("myGame", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("myGame");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);

    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
    /*auto frameSize = glview->getFrameSize();
    // if the frame's height is larger than the height of medium size.
    if (frameSize.height > mediumResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is larger than the height of small size.
    else if (frameSize.height > smallResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is smaller than the height of medium size.
    else
    {        
        director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
    }*/

    register_all_packages();

	//提前将所有图片加入缓存
	SpriteFrameCache *frame_cache = SpriteFrameCache::getInstance();
	frame_cache->addSpriteFramesWithFile("texture.plist", "texture.png");

	//将敌机爆炸动作加入AnimationCache
	Vector<SpriteFrame *> enemy_explode_frames;
	enemy_explode_frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("explosion01.png"));
	enemy_explode_frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("explosion02.png"));
	enemy_explode_frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("explosion03.png"));
	enemy_explode_frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("explosion04.png"));
	enemy_explode_frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("explosion05.png"));
	enemy_explode_frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("explosion06.png"));
	enemy_explode_frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("explosion07.png"));
	enemy_explode_frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("explosion08.png"));
	enemy_explode_frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("explosion09.png"));
	Animation *enemy_explode_animation = Animation::createWithSpriteFrames(enemy_explode_frames, 0.03f);
	AnimationCache::getInstance()->addAnimation(enemy_explode_animation, "enemy_exploded");

    // create a scene. it's an autorelease object
    auto scene = WelcomeScene::create();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be paused
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
