// 045. Jump Game II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/jump-game-ii/
//跳跃游戏升级，记录次数
//给定一串非负整数，每个数代表能跳跃的最大长度，返回跳到尾巴的最少步数 。

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//下意识觉得是动态规划，然而并不是
/**
BFS
参考：https://blog.csdn.net/wusecaiyun/article/details/47041057
记录上一次能跳跃到的最远距离，当i>last时候，跳跃次数加1，上一次能跳到的最远距离更新为当前能跳到的最远距离
*/
class Solution {
public:
	int jump(vector<int>& nums) {
		int len = nums.size();
		if (len < 2)
			return 0;
		int ret = 0, last = 0, cur = 0;
		for (int i = 0; i < len; ++i) {
			if (i > cur)//永远也跳不出去了
				return -1;
			if (i > last) {
				last = cur;
				++ret;
			}
			cur = max(cur, nums[i] + i);
		}
		return ret;
	}
};

class Solution1 {
public:
	int jump(vector<int>& nums) {
		int start = 0, end = 0, res = 0;
		while (end < nums.size() - 1) {
			int max_pos = 0;
			//计算下一个范围的终点
			for (int i = start; i <= end; i++) {
				max_pos = max(max_pos, i + nums[i]);
			}
			start = end + 1;//下一个范围的起点为当前终点+1
			end = max_pos;
			res++;//移动一个范围
		}
		return res;
	}
};



int main()
{
	vector<int> nums = { 5,9,3,2,1,0,2,3,3,1,0,0 };
	cout << Solution().jump(nums) << endl;
	std::cout << "Hello World!\n";
}
