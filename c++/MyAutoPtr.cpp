#include<iostream>
#include<string>
using namespace std;
class MyString
{
public:
	MyString();
	MyString(int len);//创建一个长度len的string对象
	MyString(const char* str);//字符串初始化
	MyString(const MyString& another);//拷贝

	~MyString();
	//重载运算符[]
	char& operator [](int index);
	//重载运算符<<
	friend ostream& operator<<(ostream&os, MyString&s);
	//重载运算符>>
	friend istream& operator>>(istream&os, MyString&s);
	//重载运算符==
	bool operator==(MyString&another);
	//重载运算符+
	MyString operator+(MyString& another);//如果是返回引用是一个临时对象的引用，所以返回值
	//重载运算符=
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

	//memset(temp.str, 0, len + 1);//清空
	strcpy(temp.str, this->str);//strcat就要清空  不知道拼哪去了
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
	//1.将s之前的字符串释放
	if (s.str != NULL)
	{
		delete[]s.str;
		s.str = NULL;
		s.len = 0;
	}
	//2.通过cin添加新的字符串 通过临时变量
	char temp[4096] = { 0 };//局部会自己释放
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
MyString::MyString(const MyString& another)//初始化的时候被调用
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
	//1.检查自己赋值
	if (this == &another)
	{
		return *this;
	}
	//2.释放垃圾
	if (this->str != NULL)
	{
		delete []this->str;
		this->str = NULL;
		this->len = 0;
	}
	//3.深拷贝
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