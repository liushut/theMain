#include<iostream>
#include<string>
using namespace std;
class MyString
{
public:
	MyString();
	MyString(int len);//����һ������len��string����
	MyString(const char* str);//�ַ�����ʼ��
	MyString(const MyString& another);//����

	~MyString();
	//���������[]
	char& operator [](int index);
	//���������<<
	friend ostream& operator<<(ostream&os, MyString&s);
	//���������>>
	friend istream& operator>>(istream&os, MyString&s);
	//���������==
	bool operator==(MyString&another);
	//���������+
	MyString operator+(MyString& another);//����Ƿ���������һ����ʱ��������ã����Է���ֵ
	//���������=
	MyString& operator=(const MyString& another);
private:
	int len;
	char* str;
};
char &MyString::operator[](int index)
{
	return this->str[index];
}
MyString MyString::operator+(MyString&another)
{
	MyString temp;
	int len = this->len + another.len;
	temp.len = len;
	temp.str = new char[len + 1];

	//memset(temp.str, 0, len + 1);//���
	strcpy(temp.str, this->str);//strcat��Ҫ���  ��֪��ƴ��ȥ��
	strcat(temp.str, another.str);
	return temp;
}
bool MyString::operator==(MyString&another)
{
	if (this->len == another.len)
	{
		return true;
	}
	else
	{
		return false;
	}
}
istream& operator>>(istream&is, MyString&s)
{
	//1.��s֮ǰ���ַ����ͷ�
	if (s.str != NULL)
	{
		delete[]s.str;
		s.str = NULL;
		s.len = 0;
	}
	//2.ͨ��cin����µ��ַ��� ͨ����ʱ����
	char temp[4096] = { 0 };//�ֲ����Լ��ͷ�
	cin >> temp;
	int len = strlen(temp);
	s.str = new char[len + 1];
	strcpy(s.str, temp);
	s.len = len;
	return is;


}
ostream& operator<<(ostream&os, MyString&s)
{
	os << s.str << endl;
}
MyString::MyString()
{
	this->len = 0;
	this->str = NULL;
}

MyString::~MyString()
{
	if (this->str != NULL)
	{
		delete this->str;
		this->str = NULL;
		this->len = 0;
		cout << "~MyString()" << endl;
	}
}
MyString::MyString(const MyString& another)//��ʼ����ʱ�򱻵���
{
	
	this->len = another.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, another.str);

}
MyString::MyString(const char* str)
{
	if (str == NULL)
	{
		this->len = 0;
		this->str = new char[0 + 1];
		strcpy(this->str, "");
	}
	else
	{
		int len = strlen(str);
		this->len = len;
		this->str = new char[len + 1];
		strcpy(this->str, str);
	}
}
MyString& MyString::operator=(const MyString& another)
{
	//1.����Լ���ֵ
	if (this == &another)
	{
		return *this;
	}
	//2.�ͷ�����
	if (this->str != NULL)
	{
		delete []this->str;
		this->str = NULL;
		this->len = 0;
	}
	//3.���
	this->len = another.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, another.str);

	return *this;
}
class A
{
public:
	A() {
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;

	}
	void fun()
	{
		cout << "fun()" << endl;
	}
};
class  MyPtr
{
public:
	 MyPtr(A* a);
	~MyPtr();

	A* operator->()
	{
		return ptr;

	}
private:
	
	A* ptr;
};

 MyPtr::MyPtr(A* a)
{
	 this->ptr = a;
}

 MyPtr::~MyPtr()
{
	 if (this->ptr != NULL)
	 {
		 delete ptr;
		 this->ptr = NULL;
	 }
}
 void Fun()
 {
	 MyPtr my(new A());
	 my->fun();
 }
 int main()
 {
	 Fun();
	 return 0;
 }