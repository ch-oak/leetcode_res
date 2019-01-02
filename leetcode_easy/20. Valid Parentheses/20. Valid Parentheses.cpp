// 20. Valid Parentheses.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给一串括号，判断括号是否互相配对。

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

/**
*以前做过有点印象，使用栈来做，当栈不为空且新压入栈的括号能与栈顶元素配对的时候，删除栈顶元素。否则压入。
*最后判断栈是否为空，为空则正确，不为空则错误。
*/

class Solution {
public:
	bool isValid(string s) {
		map<char, char> bracket = { {')','('},{']','['},{'}','{'} };
		stack<char> sta;
		int len = s.size();
		for (int i = 0; i < len; i++) {
			if (!sta.empty()&&bracket.find(s[i])!=bracket.end()&&bracket[s[i]] == sta.top())
				sta.pop();
			else
				sta.push(s[i]);
		}
		return sta.empty();

	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	Solution sol;
	string s;
	while (cin >> s) {
		cout << sol.isValid(s) << endl;
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
