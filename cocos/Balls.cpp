#include "Balls.h"

bool Balls::init()
{
	Sprite::initWithFile("ball.png");
	//m_speedX = CCRANDOM_0_1() * 10 - 5;
	//m_speedY = CCRANDOM_0_1() * 10 - 5;
	m_speed = Vec2(CCRANDOM_0_1()*10, CCRANDOM_0_1()*15-5);
	visibleSize = Director::getInstance()->getVisibleSize();
	return true;
}
void Balls::Move()
{
	setPosition(getPosition() + m_speed);
	if (getPositionX() < 0 || getPositionX() > visibleSize.width - getContentSize().width / 2)
	{
		m_speed.x *= -1;
	}
	else if (getPositionY() < 0 || getPositionY() > visibleSize.height - getContentSize().height / 2)
	{
		m_speed.y *= -1;
	}
	/*setPosition(getPositionX() + m_speedX, getPositionY() + m_speedY);
	if (getPositionX() < getContentSize().width/2)
	{
		m_speedX = fabs(m_speedX);
	}
	if (getPositionX() > visibleSize.width - getContentSize().width / 2)
	{
		m_speedX = -fabs(m_speedX);
	}
	if (getPositionY() < getContentSize().height / 2)
	{
		m_speedY = fabs(m_speedY);
	}
	if (getPositionY() > visibleSize.height - getContentSize().height / 2)
	{
		m_speedY = -fabs(m_speedY);
	}*/
}
