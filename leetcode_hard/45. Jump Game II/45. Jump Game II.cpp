// 45. Jump Game II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


int main()
{
	vector<int> nums = { 5,9,3,2,1,0,2,3,3,1,0,0 };
	cout << Solution().jump(nums);
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
