// 22. Generate Parentheses.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一个数字n,s生成有n个括号的所有正确的形式

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
*参考：http://www.cnblogs.com/grandyang/p/4444160.html
*列出所有结果的题一般使用递归方法，逐渐加括号，当剩余的左括号大于右括号数目时，直接返回
*还剩左括号则在尾巴上添加左括号，还剩右括号则在尾巴上添加右括号。
*感觉这种方法的前提是，只要某一步的左括号大于等于右括号，就一定是正确的。
*/
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		int left = n, right = n;
		vector<string> res;
		dfs(res, "", left, right);
		return res;
	}
private:
	void dfs(vector<string> &res, string now,int left, int right) {
		if (left > right)
			return;
		if (left == 0 && right == 0)
			res.push_back(now);
		else {
			if (left>0) dfs(res, now + '(', left - 1, right);
			if (right>0) dfs(res, now + ')', left, right - 1);
		}
	}
};
int main()
{
	freopen("in.txt", "r", stdin);
	int tmp;
	Solution s;
	while(cin>>tmp){
		auto res = s.generateParenthesis(tmp);
		for (auto s : res)
			cout << s << endl;
		cout << "=================================" << endl;
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
