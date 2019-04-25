// 80. Remove Duplicates from Sorted Array II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//移去重复数组里的重复数字
//Tag:Array Two Pointers

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

//参考：https://www.cnblogs.com/grandyang/p/4329295.html
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		if (len <= 2)
			return len;
		int pre = 0, cur=1;
		int count = 1;
		while (cur < len) {
			if (nums[pre] == nums[cur] && count == 0)
				cur++;
			else {
				if (nums[pre] == nums[cur]) {
					count = 0;
				}
				else {
					count = 1;
				}
				nums[++pre] = nums[cur++];//如果仅在不同的时候赋值，可能最先最后一个数两次重复但是未赋值的情况
			}
		}
		return pre + 1;
	}
};

int main()
{
	vector<int> nums{ 0,0,1,1,1,1,2,3,3 };
	cout << Solution().removeDuplicates(nums);
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
