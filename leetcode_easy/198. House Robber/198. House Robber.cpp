// 198. House Robber.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//不能选取相邻的数字，能获得的最大值
//Dynamic Programming
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>


//一维动态规划：https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		int len = nums.size();
		vector<int> rob(len + 1, 0);
		if (len == 0)
			return 0;
		rob[0] = nums[0];
		if (len == 1)
			return nums[0];
		rob[1] = max(nums[0], nums[1]);
		for (int i = 2; i < len; i++) {
			rob[i] = max(nums[i] + rob[i - 2], rob[i - 1]);
		}
		return rob[len - 1];
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
