// 84. Largest Rectangle in Histogram.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>


using namespace std;

/**
*神奇的算法
*https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/28900/O(n)-stack-based-JAVA-solution
*/
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int res = 0;
		stack<int> st;
		heights.push_back(0);
		for (int i = 0; i < heights.size(); ++i) {
			if (st.empty() || heights[st.top()] < heights[i])
				st.push(i);
			else {
				int tp = st.top();
				st.pop();
				res = max(res, heights[tp] * (st.empty() ? i : i - st.top() - 1));
				i--;
			}
		}
		return res;
	}
};

int main()
{
	vector<int> heights = { 2,1,5,6,2,3 };
	cout << Solution().largestRectangleArea(heights);
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
