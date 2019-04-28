// 121. Best Time to Buy and Sell Stock.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//买卖股票的最佳时间，给定一个数组表示价格，买卖一次股票所得的最大收益

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//最直接的算法，两层循环
class Solution1 {
public:
	int maxProfit(vector<int>& prices) {

		int len = prices.size();
		if (len <= 1)
			return 0;
		int res = 0;
		for (int i = 0; i < len -1; i++) {
			for (int j = i + 1; j < len; j++) {
				int profit = prices[j] - prices[i];
				if (prices[j] > prices[i] && profit > res)
					res = profit;
			}
		}
		return res;
	}
};

//一次遍历，但是不太好理解
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int res = 0, maxCur = 0;
		for (int i = 1; i < prices.size(); i++) {
			maxCur = max(0, maxCur + prices[i] - prices[i - 1]);//从买入点到卖出点，如果碰到了更小的买入点会更新
			cout << maxCur << endl;
			res = max(res, maxCur);
		}

		return res;
	}
};


//同样的一次遍历，但是很容易理解的算法
int maxProfit(vector<int> &prices) {
	int maxPro = 0;
	int minPrice = INT_MAX;
	for (int i = 0; i < prices.size(); i++) {
		minPrice = min(minPrice, prices[i]);
		maxPro = max(maxPro, prices[i] - minPrice);
	}
	return maxPro;
}
int main()
{
	vector<int> prices{ 7,1,5,3,6,4 };
	cout << Solution().maxProfit(prices);
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
