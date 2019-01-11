// 28. Implement strStr().cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/**
朴素的模式匹配算法
*/
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty())
			return 0;
		int i = 0, j = 0, len_des = haystack.size(), len_need = needle.size();
		while (i < len_des && j < len_need) {
			if (haystack[i] == needle[j]) {
				i++;
				j++;
			}
			else {
				i = i - j + 1;
				j = 0;
			}
		}
		if (j == len_need)
			return i - len_need;
		else
			return -1;
		
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	string haystack, needle;
	Solution s;
	while (cin >> haystack >> needle) {
		cout << s.strStr(haystack, needle) << endl;
	}
    std::cout << "Hello World!\n"; 
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
