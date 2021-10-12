//ʵ��String��ĳ�Ա������
//bool IsSubstring(const char* str) �ж��ַ���str�Ƿ�Ϊ��ǰString������Ӵ������򷵻�true, ���򷵻�false��
//bool IsSubstring(const String& str) �ж�String����str�Ƿ�Ϊ��ǰString������Ӵ������򷵻�true, ���򷵻�false��
//int str2num() ����ǰString����ת��Ϊ���֣�ת��ʱ���Գ�����������ַ���
//�����������������統ǰ�ַ���Ϊ1t2e3s4y5, ִ��str2num ����12345��

//void toUppercase()��String���ַ�������ĸȫ��ת��Ϊ��д��ĸ��
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