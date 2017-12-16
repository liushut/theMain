#pragma once
#include"cocos2d.h"
USING_NS_CC;
class Balls:public Sprite
{
public:
	virtual bool init();
	CREATE_FUNC(Balls);
	void Move();
	
private:
	float m_speedX;
	float m_speedY;
	Size visibleSize;
	Vec2 m_speed;
	
};

