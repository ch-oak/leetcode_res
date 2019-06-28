// 560. Subarray Sum Equals K.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/subarray-sum-equals-k/

/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

#include "pch.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
sum(i,j) = sum(0,j)-sum(0,i)
*/
//class Solution {
//public:
//	int subarraySum(vector<int>& nums, int k) {
//		if (nums.empty())
//			return 0;
//		vector<int> note(nums.size()+1,0);
//		int res = 0;
//		for (int i = 0; i < nums.size(); i++) {
//			note[i+1] = note[i] + nums[i];
//		}
//		for (int i = 0; i < nums.size()-1; i++) {
//			for (int j = i + 1; i < nums.size(); i++) {
//				if (note[j] - note[i] == k)
//					res++;
//			}
//		}
//		return res;
//	}
//};


class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		if (nums.empty())
			return 0;
		int sum = 0,cnt = 0;
		unordered_map<int,int> hash;
		hash[0] = 1;//如果第一个元素刚好为k的话要加上sum-k等于0，增加一个计数

		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			cnt += hash[sum - k];//加上从头开始和为sum-k的序列数目。
			++hash[sum];
		}

		return cnt;
	}
};

int main()
{
	vector<int> nums{ 2,1,1 };
	Solution().subarraySum(nums, 1);
    std::cout << "Hello World!\n"; 
}
