#include<string>
#include<iostream>
using namespace std;
void replace_string(string &s, string&old, string & newvalue)
{
	auto oldlen = old.size();
	if (!oldlen)//如果为空
	{
		return;
	}
	auto it = s.begin();
	//开始查找
	while (it <= s.end() - oldlen)//后面的部分不用管了
	{
		auto it1 = it;
		auto it2 = old.begin();
		//s中it开始的字串必须每个都要与old相同
		while (*it1 == *it2&&it2 != old.end())
		{
			it1++;
			it2++;
		}

		if (it2 == old.end())//说明遍历成功，值都相等
		{
			it = s.erase(it, it1);//s删除old相等的部分
			if (newvalue.size())
			{
				it2 = newvalue.end();//从后面往前面插入  遍历的时候就是正确顺序
				do
				{
					it2--;
					it = s.insert(it, *it2);
				} while (it2 > newvalue.begin());//先-- 所以最后会等于begin
			}
			it += newvalue.size();
		}
		else
		{
			it++;
		}
	}
}

void replace_s1(string &s, string&old, string & newvalue)
{
	int p = 0;
	while ((p = s.find(old, p)) != string::npos)
	{
		s.replace(p, old.size(), newvalue);
		p += newvalue.size();
	}
}
string& FrontStringBack(string&s, string&s1, string&s2)
{
	auto i = s.begin();
	auto i1 = s1.end();
	do
	{
		i1--;
		i = s.insert(i,*i1);
	} while (i1 > s1.begin());
	i += s1.size();
	s.append(s2);
	return s;

}





int main()
{
	//string s = "tho thru tho!";
	//string s1 = "thru";
	//string s2="through";
	//replace_s1(s, s1,s2 );
	//cout << s << endl;
	string s = "LST";
	string s1 = "Mr";
	string s2 = "Jr";
	s = FrontStringBack(s, s1, s2);
	cout << s << endl;

	return 0;
}