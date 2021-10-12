//实现String类的成员方法：
//bool IsSubstring(const char* str) 判定字符串str是否为当前String对象的子串，是则返回true, 否则返回false。
//bool IsSubstring(const String& str) 判断String对象str是否为当前String对象的子串，是则返回true, 否则返回false。
//int str2num() 将当前String对象转化为数字，转换时忽略出数字以外的字符，
//不考虑溢出的情况，如当前字符串为1t2e3s4y5, 执行str2num 返回12345。

//void toUppercase()将String的字符串的字母全部转化为大写字母。
#include"CString.h"

bool String::IsSubstring(const char* str)
{
	int str_len = 0;
	while (str[str_len] != '\0')
	{
		str_len++;
	}

	for (int index = 0; index <= this->len - str_len + 1; index++)
	{
		int i = 0;
		while (mystr[index] == str[i])
		{
			i++;
			index++;
			if (i == str_len) return true;
		}
		index = index - i;
	}

	return false;
}

int main()
{
	String a("ZhipengXiong");
	char b[5] = { "peng" };
	cout << a.IsSubstring(b) << endl;

	return 0;
}