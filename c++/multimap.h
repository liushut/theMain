#pragma once
#include<iostream>
#include<string>
#include<map>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;
class IsGreat
{
public:
	IsGreat(int i)
	{
		m_num = i;
	}
	bool operator()(int &num)//�����ν��
	{
		if (num > m_num)
		{
			return true;
		}
		return false;
	}
private:
	int m_num;

};
bool yi(int num);
void adj();
int te(int a);
void ff(int b);
//class Person
//{
//public:
//	string name;
//	int		age;
//	string	te1;
//	double	sal;
//};
//void fun();
//template <typename T>
//class Show
//{
//public:
//	void operator()(T &t)
//	{
//		cout << t << " " << endl;
//	}
//};
//template <typename T>
//void Fun(T&t)
//{
//	cout << "����ģ��<<"<<t << endl;
//}
//void fun2dfdf(int &t)
//{
//	cout << "��ͨ����" <<t<< endl;
//}
//void fun1ssssfgdfgdfg()
//{
//	Show<int>show;
//	int a = 666;
//	show(a);//��������ĵ��ú���������
//	Fun<int>(a);
//	
//}
void mytest();
void tfun();
