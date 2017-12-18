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
	int _row;//����
	int _columns;//����
	int _sliceWidth;//���ӵĿ��
	int _sliceHeight;//�߶�
	bool initWithPhotos(const char*photo, int row, int columer);
	vector<vector<Sprite*>> _slices;//�洢��
	void initTouchEventListerner();
	bool initSlices(const char*photo);
	void move(int x, int y);
public:
	void restart();
};

