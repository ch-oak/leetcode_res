// 055. Jump Game.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
*想法3：Solution里回溯，超时了
*/
class Solution3 {
public:
	bool canJump(vector<int>& nums) {
		return canJumpFromPosition(0, nums);
	}
private:
	bool canJumpFromPosition(int pos, vector<int>& nums) {
		if (pos == nums.size() - 1)
			return true;
		int furthestJump = std::min(pos + nums[pos], int(nums.size() - 1));
		for (int nextPos = pos + 1; nextPos <= furthestJump; nextPos++) {
			if (canJumpFromPosition(nextPos, nums))
				return true;
		}
		return false;
	}
};

/**
*想法4：Solution里自顶向下的动态规划，相比回溯多了记忆
*/
enum Index { GOOD, BAD, UNKNOWN };

class Solution4 {
public:
	bool canJump(vector<int>& nums) {
		memo = new Index[nums.size()];
		for (int i = 0; i < nums.size(); i++)
			memo[i] = Index::UNKNOWN;
		memo[nums.size() - 1] = Index::GOOD;
		return canJumpFromPosition(0, nums);
	}
private:
	Index *memo;

	bool canJumpFromPosition(int pos, vector<int>& nums) {
		if (memo[pos] != Index::UNKNOWN)
			return memo[pos] == Index::GOOD ? true : false;
		int furthestJump = std::min(pos + nums[pos], int(nums.size() - 1));
		for (int nextPos = pos + 1; nextPos <= furthestJump; nextPos++) {
			if (canJumpFromPosition(nextPos, nums)) {
				memo[pos] = Index::GOOD;
				return true;
			}
		}
		memo[pos] = Index::BAD;
		return false;
	}
};

/**
*想法5：Solution里自底向上的动态规划,不用递归，速度更块
*/
class Solution {
public:
	bool canJump(vector<int>& nums) {
		memo = new Index[nums.size()];
		for (int i = 0; i < nums.size(); i++)
			memo[i] = Index::UNKNOWN;
		memo[nums.size() - 1] = Index::GOOD;

		for (int i = nums.size() - 2; i >= 0; i--) {
			int furthestJump = std::min(i + nums[i], int(nums.size() - 1));
			for (int j = i + 1; j <= furthestJump; j++) {//半段memo[i]是否为GOOD
				if (memo[j] == GOOD) {
					memo[i] = GOOD;
					break;
				}
			}
		}
		return memo[0] == GOOD;
	}
private:
	Index *memo;
};

/**
*想法2：https://leetcode.com/problems/jump-game/discuss/20917/Linear-and-simple-solution-in-C%2B%2B
*记录能到达的最远距离
*/
class Solution2 {
public:
	bool canJump(vector<int>& nums) {
		int i = 0;
		int len = nums.size();
		for (int reach = 0; i < nums.size() && i <= reach; i++)//小于reach使得不会遍历到到达不了的地方
			reach = max(i + nums[i], reach);
		return i == len;
	}
};

int main()
{
	vector<int> nums = { 2,3,1,1,4 };
	cout << Solution().canJump(nums) << endl;
	std::cout << "Hello World!\n";
}
