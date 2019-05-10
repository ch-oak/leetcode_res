// 309. Best Time to Buy and Sell Stock with Cooldown.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
//股票可多次交易，只能持有一支股票，卖出后第二天不能再购买
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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
