// 238. Product of Array Except Self.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/product-of-array-except-self/
//其他数的乘积
//Tag:Array

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
//不能使用除法，时间复杂度在O(n),不适用额外空间
//参考：https://leetcode.com/problems/product-of-array-except-self/discuss/65622/Simple-Java-solution-in-O(n)-without-extra-space
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> res(len);
		res[0] = 1;
		for (int i = 1; i < len; i++) {
			res[i] = res[i - 1] * nums[i - 1];//某数左边的乘积
		}
		int right = 1;
		for (int i = len - 1; i >= 0; i--) {
			res[i] *= right;
			right *= nums[i];//某数右边的乘积
		}
		return res;
	}
};

int main()
{
	vector<int> nums{ 1,2,3,4 };
	Solution().productExceptSelf(nums);
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
