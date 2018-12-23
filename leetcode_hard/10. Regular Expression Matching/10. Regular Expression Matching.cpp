// 10. Regular Expression Matching.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

/**
*Hard的题还是好难呀，不能用简单的循环来完成。用到了递归，需要考虑的条件也很多，很容易考虑不周全
*这篇博客说的很好：http://www.cnblogs.com/grandyang/p/4461713.html
*
*/


class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();
		if (p.size() == 1)
			return(s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
		if (p[1] != '*') {
			if (s.empty()) return false;
			return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}
		while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
			if (isMatch(s, p.substr(2))) return true;//p[0]重复0次
			s = s.substr(1);//p[0]暂时重复一次
		}
		return isMatch(s, p.substr(2));//结束*的作用
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	string s, p;
	Solution sol;
	while (cin >> s >> p) {
		cout << sol.isMatch(s, p) << endl;
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
