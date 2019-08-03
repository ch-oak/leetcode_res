// 0300. Longest Increasing Subsequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/longest-increasing-subsequence/
//最长递增子序列
//Tag:Binary_Search DP

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//参考：https://blog.csdn.net/lanchunhui/article/details/51611970
//dp[i]是以i作为子序列的尾元素的最长序列，并不是整个字符串的最长子序列
//最长子序列可能以任何一个元素作为结尾，所以是dp数组中的最大值。
class Solution{ 
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int len = nums.size();
		vector<int> dp(len, 1);
		int res = 1;
		for (int i = 1; i < len; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[j] < nums[i])
					dp[i] = max(dp[i], dp[j] + 1);
			}
			res = max(res, dp[i]);
		}
		return res;
	}
};
