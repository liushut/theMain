#include"multimap.h"
//void fun()
//{
//	Person person1, person2, person3, person4, person5;
//	person1.name = "王五";
//	person1.age = 31;
//	person2.name = "王六";
//	person2.age = 32;
//	person3.name = "王七";
//	person3.age = 33;
//	person4.name = "王八";
//	person4.age = 34;
//	person5.name = "王九";
//	person5.age = 35;
//
//	multimap<string, Person> map2;
//	map2.insert(make_pair("sale", person1));
//	map2.insert(make_pair("sale", person2));
//
//	//development部门
//	map2.insert(make_pair("development", person3));
//	map2.insert(make_pair("development", person4));
//
//	//Finanacial
//	map2.insert(make_pair("Finanacial", person5));
//	for (multimap<string, Person>::iterator it = map2.begin(); it != map2.end(); it++)
//	{
//		cout << it->first << "\t" << it->second.name << endl;
//	}
//	cout << "遍历结束" << endl;
//
//	int num = map2.count("development");
//	cout << "development人数" << map2.count("development") << endl;
//
//	//
//	cout << "部门员工信息:" << endl;
//	int tag = 0;
//	multimap<string, Person>::iterator it2 = map2.find("development");
//	while(it2!=map2.end()&&tag<num)
//	{
//		cout << it2->first << it2->second.name << endl;
//		it2++;
//		tag++;
//	}
//	multimap<string, Person>::iterator it3 = map2.begin();
//	while (it3 != map2.end())
//	{
//		if (it3->second.age == 33)
//		{
//			it3->second.name = "大傻逼";
//		}
//		it3++;
//	}
//	for (multimap<string, Person>::iterator it4 = map2.begin(); it4 != map2.end(); it4++)
//	{
//		cout << it4->first << "\t" << it4->second.name << endl;
//	}
//}
void mytest()
{
	plus<int> p1Add;
	int x = 23;
	int y = 44;
	int z = p1Add(x, y);
	cout << z << endl;
	plus<string>dd;
	string s1 = "aa";
	string s2 = "gfgf";
	string s3 = dd(s1, s2);
	cout << s3 << endl;
}
void tfun()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << endl;
	}
	int num = count(v1.begin(), v1.end(), 3);
	cout << "num" << num << endl;
	//通过谓词求大于3
	int num2 = count_if(v1.begin(), v1.end(), IsGreat(2));
	cout << "num2" << num2 << endl;

	//通过预定义的函数对象求大于6
	int num3 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(),6));
	cout << "num3" << num3 << endl;

	int num4 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
	cout << "num4" << num4 << endl;
	int num5 = count_if(v1.begin(), v1.end(), not1(bind2nd(modulus<int>(), 2)));
	cout << "num5" << num5 << endl;
}
int te(int a)
{
	cout << "调用te" << endl;
	return a;
}
void ff(int b)
{
	cout << "调用ff" << endl;
	cout << b<< endl;
}
bool yi(int num)
{
	if (num > 3)
	{
		return true;
	}
	return false;
}
void adj()
{

	vector<int> v1{ 1, 2, 3, 4 };
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(9);
	vector<int>::iterator it1 = v1.begin();
	for (; it1 != v1.end(); it1++)
	{
		cout << *it1 << endl;
	}
	vector<int>::iterator it = adjacent_find(v1.begin(), v1.end()); 
	if (it == v1.end())
	{
		cout << "not found " << endl;
	}
	else {
		cout << *it << endl;
	}
	int index = distance(v1.begin(), it);
	cout << index << endl;
	int tt = count_if(v1.begin(), v1.end(), yi);
	cout << "大于3" << tt << endl;
}