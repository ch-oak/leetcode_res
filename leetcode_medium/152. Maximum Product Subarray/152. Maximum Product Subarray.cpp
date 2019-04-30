// 152. Maximum Product Subarray.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//连续子数组的最大乘积
//Array Dynamic Programming

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
	int maxProduct(vector<int>& nums) {
		int len = nums.size();
		int res = nums[0];
		for (int i = 0; i < len; i++) {
			for (int j = i; j < len; j++) {
				int temp = 1;
				for (int k = i; k <= j; k++) {
					temp *= nums[k];
				}
				if (temp > res)
					res = temp;
			}
		}
		return res;
	}
};


//动态规划
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int res = nums[0];
		int len = nums.size();
		vector<int> dp_min(len); dp_min[0] = res;
		vector<int> dp_max(len); dp_max[0] = res;
		for (int i = 1; i < len; i++) {
			dp_min[i] = min(min(dp_min[i - 1] * nums[i], dp_max[i - 1] * nums[i]), nums[i]);//包括还是不包括nums[i]
			dp_max[i] = max(max(dp_min[i - 1] * nums[i], dp_max[i - 1] * nums[i]), nums[i]);
			res = max(dp_max[i], res);
		}
		return res;
	}
};
class Solution3 {
public:
	int maxProduct(vector<int>& nums) {
		int res = nums[0];
		int len = nums.size();
		for (int i = 1, imin = res, imax = res; i < len; i++) {//imin,imax表示以i为终点的最小乘积和最大乘积
			if (nums[i] < 0)
				swap(imin, imax);
			imin = min(nums[i], nums[i] * imin);//包括还是不包括nums[i]
			imax = max(nums[i], nums[i] * imax);
			res = max(imax, res);
		}
		return res;
	}
};

int main()
{
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
