// 322. Coin Change.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/coin-change/
//换零钱可能换不出来，动态规划的结构与最强递增子序列类似
//Tag:DP


#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//参考：https://cloud.tencent.com/developer/article/1403624
//动态规划，需要考虑不能兑换的情况
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, amount + 1);//全用1兑换，最多兑换amount次
		dp[0] = 0;//注意初始化
		for (int i = 1; i <= amount; i++) {
			for (int j = 0; j < coins.size(); j++) {
				if (i >= coins[j])
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}

		if (dp[amount] == amount + 1)
			return -1;
		return dp[amount];
	}
};

int main()
{
	vector<int> coins{ 1,2,5 };
	int amount = 11;
	Solution().coinChange(coins, amount);
	std::cout << "Hello World!\n";
}