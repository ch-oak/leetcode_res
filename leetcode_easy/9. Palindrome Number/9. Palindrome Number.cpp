// 9. Palindrome Number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

//直接变为字符串反转比较
class Solution1 {
public:
	bool isPalindrome(int x) {
		string str = to_string(x);
		string str_rev(str);
		reverse(str_rev.begin(), str_rev.end());
		if (str == str_rev)
			return true;
		else
			return false;
	}
};
//只比较一半
class Solution2 {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x != 0 && x % 10 == 0))
			return false;
		int xr = 0;
		while (x > xr) {//xr等于(偶数位）或大于x（奇数位）
			xr = xr * 10 + x % 10;
			x = x / 10;
		}
		return (x == xr) || (x == xr / 10);
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	int temp;

	Solution2 s;
	while (cin >> temp) {
		cout << s.isPalindrome(temp) << endl;
	}

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
