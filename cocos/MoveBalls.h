#pragma once

#include "cocos2d.h"
USING_NS_CC;
class MoveBalls : public cocos2d::LayerColor
{
public:
	virtual bool init() ;

	static Scene* Createscene();

	// implement the "static create()" method manually
	CREATE_FUNC(MoveBalls);
	virtual void update(float t);

private:

};

