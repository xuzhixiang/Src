#include <iostream>
#include <cstdio>
#include "implicit_string.h"

using namespace std;
using namespace MS;

int main()
{
	ms_string s;
	ms_string str("1234");
	ms_string str1(str);
	ms_string str2 = str;
	// 隐式共亨，地址为一样的
	printf("%p-%p-%p\n", &str.test(1), &str1.test(1), &str2.test(1));
	cout << str1.c_str() << endl;
	str.append('6');
	cout << str1.c_str() << ' ' << str.c_str() << endl;
	str.append("123");
	cout << str1.c_str() << ' ' << str.c_str() << endl;
	cout << str1.size() << ' ' << str.size() << endl;
	return 0;
}

