// 32. Longest Valid Parentheses.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给出一个只包含"("和")"的字符串，找出里面最长的括号的长度

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <set>

using namespace std;

/**
*首先想用栈来考虑到前面做的有效括号判断，想用栈来判断，但是不太合适。这里求的最长的连续的有效括号
*参考：https://leetcode.com/problems/longest-valid-parentheses/discuss/14126/My-O(n)-solution-using-a-stack
*用栈记录所有异常点，巧妙之处在于有效括号一定是连续的，对于异常括号的存储，存储的是下标
*/

class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.empty())
			return 0;
		int len = s.size();
		stack<int> index;
		for (int i = 0; i < len; i++) {
			if (s[i] == '(') index.push(i);
			else {
				if (index.empty())
					index.push(i);
				else if (s[index.top()] == '(')
					index.pop();
				else
					index.push(i);
			}
	
		}
		if (index.empty())
			return len;
		int max = 0;
		int next = len;
		int cur;
		while (!index.empty()) {
			cur = index.top();
			max = max > next-cur - 1 ? max : next - cur - 1;
			next = cur;
			index.pop();
		}
		max = max > next  ? max : next;
		return max;
	}
};
int main()
{
	freopen("in.txt", "r", stdin);
	string s;
	Solution sol;
	while (cin >> s) 
		cout << sol.longestValidParentheses(s) << endl; 
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
