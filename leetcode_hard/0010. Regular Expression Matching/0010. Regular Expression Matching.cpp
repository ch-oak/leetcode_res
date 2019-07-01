// 0010. Regular Expression Matching.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//String DP BackTracking
//Hard
//模式p是否能匹配字符串s
//https://leetcode.com/problems/regular-expression-matching/

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

/**
*Hard的题还是好难呀，不能用简单的循环来完成。用到了递归，需要考虑的条件也很多，很容易考虑不周全
*这篇博客说的很好：http://www.cnblogs.com/grandyang/p/4461713.html
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
