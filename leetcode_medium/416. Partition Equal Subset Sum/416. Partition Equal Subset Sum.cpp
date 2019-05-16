// 416. Partition Equal Subset Sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/partition-equal-subset-sum/
//能否将数组分为和相等的两个子集

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//参考：https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation
//动态规划
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		if (nums.empty())
			return true;
		int maxEle = *max_element(nums.begin(), nums.end());
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
			sum += nums[i];
		int half = sum / 2;
		if (2 * half != sum)
			return false;

		vector<vector<bool>> dp(nums.size()+1, vector<bool>(half+1, false));
		for (int i = 1; i < nums.size()+1;i++)
			dp[i][0] = true;
		for (int j = 1; j < half + 1; j++)
			dp[0][j] = false;
		dp[0][0] = true;
		for (int i = 1; i < nums.size() + 1; i++) {
			for (int j = 1; j < half + 1; j++) {
				if (nums[i-1] <= j) {
					dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];//dp[i][j]表示能否有前i个元素组成j
				}
			}
		}
		return dp[nums.size()][half];
	}
};

int main()
{
	vector<int> nums{ 1, 5, 11, 5 };
	Solution().canPartition(nums);
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
