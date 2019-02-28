// 55. Jump Game.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给一个数组，数组值代表能跨越的最远距离，从第一个数字开始，能否调到最后一个数字。

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
*想法1：尝试用递归的方法做，栈溢出了
*/
class Solution1 {
public:
	bool canJump(vector<int>& nums) {
		vector<int> res;
		dfs(res, nums, 0);
		return !res.empty();
	}
private:
	void dfs(vector<int> &res, vector<int>& nums, int pos) {
		if (!res.empty())
			return;
		if (pos == nums.size() - 1)
			res.push_back(0);
		if (pos >= nums.size() || nums[pos] == 0)
			return;
		for (int i = 1; i <= nums[pos]; i++)
			dfs(res, nums, pos + i);
	}
};

/**
*想法2：https://leetcode.com/problems/jump-game/discuss/20917/Linear-and-simple-solution-in-C%2B%2B
*记录能到达的最远距离
*/
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int i = 0;
		int len = nums.size();
		for (int reach = 0; i < nums.size()&&i <= reach; i++)//小于reach使得不会遍历到到达不了的地方
			reach = max(i + nums[i], reach);
		return i==len;
	}
};

int main()
{
	vector<int> nums = { 2,3,1,1,4 };
	cout << Solution().canJump(nums) << endl;
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
