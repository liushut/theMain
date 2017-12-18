#pragma once
#include"cocos2d.h"
#include<vector>
#include<stdio.h>
using namespace std;
USING_NS_CC;
class Photo:public Layer
{
public:
	Photo();
	~Photo();
	static Photo*CreateOne(const char*photo, int row = 3, int columer = 3);
protected:
	int _row;//行数
	int _columns;//列数
	int _sliceWidth;//格子的宽度
	int _sliceHeight;//高度
	bool initWithPhotos(const char*photo, int row, int columer);
	vector<vector<Sprite*>> _slices;//存储列
	void initTouchEventListerner();
	bool initSlices(const char*photo);
	void move(int x, int y);
public:
	void restart();
};

