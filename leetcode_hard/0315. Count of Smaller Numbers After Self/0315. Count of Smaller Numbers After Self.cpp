// 0315. Count of Smaller Numbers After Self.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//计算数组右边比当前数据小的数
//Binary Search Divide and Conquer Sort Binary Indexed Tree Segment Tree
//Har

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		int len = nums.size();
		vector<int> res(len, 0), note;
		for (int i = len - 1; i >= 0; i--) {
			auto it = lower_bound(note.begin(), note.end(), nums[i]);
			res[i] = it - note.begin();
			note.insert(it, nums[i]);
		}
		return res;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
