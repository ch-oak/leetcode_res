// 0041. First Missing Positive.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//第一个缺失的正整数
//Array
//Hard
//从1 ~ +∞的范围中，找到没有在输入数组出现过的最小的正数
//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int len = nums.size();
		for (int i = 0; i < len;i++) {
			while (nums[i] != (i + 1) && nums[i] >= 1 && nums[i] <= len && nums[nums[i] - 1] != nums[i])
				//正常情况下依次放置的话，num[i]应该等于i+1;
				//如果num[i]不等于i+1,则把num[i]放到他应该存在的位置num[i]-1上
				//继续纠正换过来的数字，直到换对或者越界，或者交换的两个数字相等就结束
				//因为所有循环，最多交换O(n)数量级，所以还是线性时间复杂度
				//如果可以使用额外空间的话，应该很简单，不对，不知道申请多少空间
				swap(nums[i], nums[nums[i] - 1]);
		}
		for (int i = 0; i < len; i++)
			if (nums[i] != (i + 1))
				return i + 1;
		return len + 1;
	}
};
int main()
{
	vector<int> nums{ 3,4,-1,1 };
	Solution().firstMissingPositive(nums);
	std::cout << "Hello World!\n";
}
