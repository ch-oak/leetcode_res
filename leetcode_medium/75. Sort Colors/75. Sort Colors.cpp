// 75. Sort Colors.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//将只含0,1,2的数组排序，使用尽量少的空间和循环次数
//Array Two Pointer Sort;

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.empty())
			return;
		int len = nums.size();
		vector<int> res(len, 1);
		int left = 0;
		int right = len - 1;
		for (int i = 0; i < len; i++) {
			if (nums[i] == 0)
				res[left++] = 0;
			else if (nums[i] == 2)
				res[right--] = 2;
		}
		nums = res;
		
		//int start = 0, end = nums.size()-1;
		//int i;
		//while (i >= start && i <= end) {
		//	if (nums[i] == 0)
		//		swap(nums[i], nums[start]);
		//	else if (nums[i] == 2)
		//		swap(nums[i], nums[end]);
		//}
	}
};

int main()
{
	vector<int> nums{ 2,0,2,1,1,0 };
	Solution().sortColors(nums);
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
