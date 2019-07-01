// 045. Jump Game II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/jump-game-ii/
//跳跃游戏升级，记录次数

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
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
    std::cout << "Hello World!\n"; 
}
