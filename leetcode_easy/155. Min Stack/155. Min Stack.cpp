// 155. Min Stack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stack>

using namespace std;

//解答：https://leetcode.com/problems/min-stack/discuss/49016/C%2B%2B-using-two-stacks-quite-short-and-easy-to-understand
//双栈，一个栈存最小值，一个栈存所有值，压入和弹出的时候，判断是否需要更新存储最小值的栈
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		numStack.push(x);
		if (minStack.empty()||x <= getMin())
			minStack.push(x);
	}

	void pop() {
		if (getMin() == numStack.top())
			minStack.pop();
		numStack.pop();
	}

	int top() {
		return numStack.top();
	}

	int getMin() {
		return minStack.top();
	}
protected:
	stack<int> minStack;
	stack<int> numStack;
};


int main()
{
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
