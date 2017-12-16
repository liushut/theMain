#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::LayerColor
{
public:
    virtual bool init() override;

    static cocos2d::Scene* scene();

    // a selector callback
    void menuCloseCallback(Ref* sender);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
	virtual void update(float t);

private:
	cocos2d::Sprite* ball;
	cocos2d::Size visiblesize;
};

#endif // __HELLOWORLD_SCENE_H__
