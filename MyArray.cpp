#pragma
#include<iostream>
using namespace std;
class  MyArray
{
public:
	 MyArray();
	 MyArray(int len);
	~ MyArray();
	//���
	MyArray(const MyArray&another);
	
	void SetData(int index, int data);
	int GetData(int index);
	int GetLen();

	void operator=(const MyArray& another);
private:
	int len;
	int*space;
};
void MyArray::SetData(int index, int data)
{
	if (this->space != NULL)
	{
		this->space[index] = data;
		
	}
	
	
}
int MyArray::GetLen()
{
	return len;
}
int MyArray::GetData(int index)
{
	return this->space[index];
}
MyArray::MyArray(int len)
{
	if (len <= 0)
	{
		len = 0;
		return;
	}
	else
	{
		this->len = len;
		//space���ٿռ�
       space = new int[len];//�����ַ=����Ԫ���׵�ַ=��������ֵ  space����������
	   cout << "MyArray::MyArray(int len)..." << endl;
	}
	
	
}
MyArray::MyArray(const MyArray&another)
{
	if (another.len >= 0)
	{
		this->len = another.len;
		//���
		space = new int[this->len];
		for (int i = 0; i < len; i++)
		{
			this->space[i] = another.space[i];
		}
		cout << "MyArray::MyArray(const MyArray&another)." << endl;
	}
	
}
 MyArray:: MyArray()
{
	 cout << "MyArray().." << endl;
	 this->len = 0;
	 this->space = NULL;

}

 MyArray::~ MyArray()
{
	 if (space != NULL)
	 {
		 delete []space;
		 space = NULL;
		 len = 0;
		 cout << "MyArray::~ MyArray()..." << endl;
	 }
}
 int main()
 {
	 MyArray array1(10);//����10��Ԫ��
	 //��ֵ
	 for (int i = 0; i < array1.GetLen(); i++)
	 {
		 array1.SetData(i, i + 10);
	 }
	 cout << "-----" << endl;
	 cout << "array1----" << endl;
	 for (int i = 0; i < 10; i++)
	 {
		 cout << array1.GetData(i) << " ";
		 
	 }
	 cout << endl;

	 MyArray array2 = array1;
	 cout << "Aaaay2---" << endl;
	 for (int i = 0; i < array2.GetLen(); i++)
	 {
		 cout << array2.GetData(i) << " ";
	 }
	 cout << endl;
	 cout << "---Aaayr3" << endl;
	 MyArray array3;
	 array3 = array2;//������������ֵ�����򵥿���������������ͬһ��ָ����ָ��Ҫ����=�����

	 return 0;
 }