#include "HelloWorldScene.h"
#include "AppMacros.h"

USING_NS_CC;


Scene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(255,255,255,255)))
    {
        return false;
    }
    
	visiblesize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();







	ball = Sprite::create("ball.png");
	ball->setPosition(Vec2(200,200));
	addChild(ball);

	scheduleUpdate();
	
    
    return true;
}
void HelloWorld::update(float t)
{
	ball->setPositionX(ball->getPositionX() + 3);
	if (ball->getPositionX() > visiblesize.width + ball->getContentSize().width/2)
	{
		ball->setPositionX(-ball->getContentSize().width/2);

	}

}

void HelloWorld::menuCloseCallback(Ref* sender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
