#include "Photo.h"



Photo::Photo():_row(3),_columns(3)
{

}


Photo::~Photo()
{
	this->removeAllChildren();
}
Photo* Photo::CreateOne(const char*photo, int row = 3, int columer = 3)
{
	Photo*cp = new Photo();
	if (cp&&cp->initWithPhotos(photo, row, columer))
	{
		cp->autorelease();
		return cp;
	}
	CC_SAFE_DELETE(cp);
	return nullptr;
}
bool Photo::initWithPhotos(const char*photo, int row, int columer)
{
	bool result = false;
	if (Layer::init())
	{
		_row = row;
		_columns = columer;
		if (initSlices(photo))
		{

			initTouchEventListerner();
			restart();
			result = true;
		}
		else
		{
			result = false;
		}
		return result;
	}
	
}
bool Photo::initSlices(const char*photo)
{
	Texture2D *texture = Director::getInstance()->getTextureCache()->addImage(photo);
	//初始化二维数组
	for (int w = 0; w < _row; ++w)
	{
		vector<Sprite*>row;
		for (int h = 0; h < _columns; h++)
		{
			row.push_back(nullptr);
		}
		_slices.push_back(row);

	}

	//计算图片大小
	auto size = texture->getContentSize();
	_sliceWidth = size.width / _row;
	_sliceHeight = size.height / _columns;
	this->setContentSize(size);//设置Layer大小

	//挖出最后一块
	auto endSlice = Sprite::createWithTexture(texture,
		Rect(_sliceWidth*(_row - 1), _sliceHeight*(_columns - 1), _sliceWidth, _sliceHeight));

	endSlice->setAnchorPoint(Vec2(0, 0));
	endSlice->setPosition(_sliceWidth*(_row - 1), 0);
	endSlice->setOpacity(100);
	this->addChild(endSlice);
	_slices[_row - 1][_columns - 1] = nullptr;

	//创建切片
	for (int w = 0; w < _row; ++w)
	{
		for (int h = 0; h < _columns; h++)
		{
			if (w == _row - 1 && h == _columns - 1)
			{
				break;
			}
			Sprite* slice = Sprite::createWithTexture(texture, Rect(
				_sliceWidth*w, _sliceHeight*h, _sliceWidth, _sliceHeight));
			slice->setAnchorPoint(Vec2(0, 0));
			slice->setPosition(w*_sliceWidth, size.height - (h + 1)*_sliceHeight);
			this->addChild(slice);
			_slices[w][h] = slice;
		}
	;

	}
	return true;
}
void Photo::initTouchEventListerner()
{
	auto listner = EventListenerTouchOneByOne::create();
	listner->onTouchBegan = [&](Touch*touch, Event*even)
	{
		Point locationInNode = this->convertToWorldSpace(touch->getLocation());
		Size s = this->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);
		if (rect.containsPoint(locationInNode))
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	listner->onTouchEnded = [&](Touch*touch, Event*even)
	{
		Point locationInNode = this->convertToWorldSpace(touch->getLocation());
		int x = static_cast<int>(floor(locationInNode.x / this->_sliceWidth));
		int y=static_cast<int>(floor(locationInNode.y / this->_sliceHeight));
		this->move(x, y);
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listner, this);
}
void Photo::move(int x, int y)
{
	y = _columns - y - 1;
	auto slice = _slices[x][y];
	if (slice == nullptr)
	{
		return;

	}
	//判断周围是否又空余格子
	bool isFind = false;
	Point targetPos;
	if (y < _columns - 1 && _slices[x][y + 1] == nullptr)
	{
		targetPos.x = x;
		targetPos.y = y;
		isFind = true;
	}
	else if (y >0 && _slices[x][y - 1] == nullptr)
	{
		targetPos.x = x;
		targetPos.y = y-1;
		isFind = true;
	}
	else if (x < _row - 1 && _slices[x+1][y] == nullptr)
	{
		targetPos.x = x + 1;
		targetPos.y = y;
		isFind = true;
	}
	else if (x>0 && _slices[x-1][y] == nullptr)
	{
		targetPos.x = x-1;
		targetPos.y = y;
		isFind = true;
	}
	if (isFind == false)
	{
		return;
	}
	slice->runAction(MoveTo::create(0.25f, Vec2(targetPos.x*_sliceWidth,
		_sliceHeight*_columns - (targetPos.y + 1)*_sliceHeight)));

	_slices[targetPos.x][targetPos.y] = slice;
	_slices[x][y] = nullptr;
}
void Photo::restart()
{
	//取出所有图块
	Vector<Sprite*> list;
	for (int w = 0; w < _row; ++w)
	{
		for (int h = 0; h < _columns; h++)
		{
			auto slice = _slices[w][h];
				if (slice != nullptr)
				{
					list.pushBack(slice);
				}
			
		}

	}

	for (int w = 0; w < _row; ++w)
	{
		for (int h = 0; h < _columns; h++)
		{
			if (w == _row - 1 && h == _columns - 1)
			{
				_slices[w][h] = nullptr;
				break;
			}
			auto length = list.size();
			auto value1 = static_cast<int>(CCRANDOM_0_1()*length);
			auto slice = list.at(value1);
			list.eraseObject(slice);
			_slices[w][h] = slice;
			slice->setPosition(w*_sliceWidth, _sliceHeight*_columns-(h+1)*_sliceHeight);

		}

	}
}