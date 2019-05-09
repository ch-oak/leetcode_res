// 283. Move Zeroes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/move-zeroes/
//移零到末尾
//Tag:Array Two_Pointers

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
	void moveZeroes(vector<int>& nums) {
		auto beg = remove(nums.begin(), nums.end(), 0);
		while (beg != nums.end()) {
			*beg = 0;
			beg++;
		}
	}
};


//双指针，一个指向非零值，一个往后找非零值
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int pos = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != 0) {
				nums[pos] = nums[i];
				pos ++ ;
			}
		}
		for (; pos < nums.size(); pos++)
			nums[pos] = 0;
	}
};

int main()
{
	vector<int> nums{ 0,1,0,3,12 };
	Solution().moveZeroes(nums);
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
