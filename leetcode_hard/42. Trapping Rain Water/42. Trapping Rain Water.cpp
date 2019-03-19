// 42. Trapping Rain Water.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一串代表海拔的非负整数，可以存多少水
//Tag:Array  Two Points  Stack

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
/**
*暴力解法：第一个海拔和最后一个海拔不会存水，其他海拔的存水量等于从该海拔向左遍历得到的最大左高度
*和从该海拔向右遍历的最大右高度中的较小者减去海拔高度（木桶理论），所有海拔存水量加起来就是总的存水量
*/

class Solution {
public:
	int trap(vector<int>& height) {
		int len = height.size();
		int ans = 0;
		for (int i = 1; i < len - 1; i++) {
			int max_left = 0, max_right = 0;
			for (int j = i; j >= 0; j--)
				max_left = max(max_left, height[j]);
			for (int j = i; j < len; j++)
				max_right = max(max_right, height[j]);
			ans += min(max_left, max_right) - height[i];
		}
		return ans;
	}
};

int main()
{
	vector<int> height{ 0,1,0,2,1,0,1,3,2,1,2,1 };
	Solution().trap(height);
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
