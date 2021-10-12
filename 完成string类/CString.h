#pragma once
#include <iostream>
using namespace std;
class String {
private:
	char* mystr;    //×Ö·û´®
	int len;    //×Ö·û´®³¤¶È
public:
	String() {
		len = 0;
		mystr = NULL;
	}
	String(const char* p) {
		len = strlen(p);
		mystr = new char[len + 1];
		strcpy(mystr, p);
	}
	String(String& s) {
		len = s.len;
		if (len != 0)
		{
			mystr = new char[len + 1];
			strcpy(mystr, s.mystr);
		}
	}
	~String() {
		if (mystr != NULL)
		{
			delete[]mystr;
			mystr = NULL;
			len = 0;
		}
	}

	char* GetStr() { return mystr; }
	void ShowStr() { cout << mystr; }

	bool IsSubstring(const char* str);
	bool IsSubstring(const String& str);
	int str2num();
	void toUppercase();
};