// 300. Longest Increasing Subsequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/longest-increasing-subsequence/
//最长递增子序列
//Tag:Binary_Search DP

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//参考：https://blog.csdn.net/lanchunhui/article/details/51611970
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		vector<int> dp(len, 1);
		int res = 1;
		int i, j;
		for (i = 1; i < nums.size(); ++i) {
			for (j = 0; j < i; j++) {
				if (nums[j] < nums[i])
					dp[i] = max(dp[i], 1 + dp[j]);
			}
			res = max(dp[i], dp[j] + 1);
		}
	}
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
