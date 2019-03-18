// 41. First Missing Positive.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//从1 ~ +∞的范围中，找到没有在输入数组出现过的最小的正数

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int len = nums.size();
		for (int i = 0; i < len;) {
			if (nums[i] != (i + 1) && nums[i] >= 1 && nums[i] <= len && nums[nums[i] - 1] != nums[i])
				//如果nums[i]-1>i则将i位置的元素扔到后面去，如果nums[i]-1<i，则将num[i]扔到前面去
				swap(nums[i], nums[nums[i] - 1]);
			else
				i++;
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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
