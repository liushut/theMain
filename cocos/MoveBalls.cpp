#include"MoveBalls.h"

Scene*MoveBalls::Createscene()
{
	auto s = Scene::create();
	auto l = MoveBalls::create();
	s->addChild(l);
	return s;
}