// 0032. Longest Valid Parentheses.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//最长有效括号
//String DP
//Hard
//给出一个只包含"("和")"的字符串，找出里面最长的括号的长度
//https://leetcode.com/problems/longest-valid-parentheses/
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
			max = max > next - cur - 1 ? max : next - cur - 1;
			next = cur;
			index.pop();
		}
		max = max > next ? max : next;
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
