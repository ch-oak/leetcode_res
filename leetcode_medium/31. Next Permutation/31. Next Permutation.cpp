// 31. Next Permutation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//输出给定排列的下一个排列组合，当不存在下一个排列组合时，返回升序排列  

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;



/**
*参考：https://blog.csdn.net/bengshakalakaka/article/details/78515480
*从后往前遍历找到第一个i小于i+1的位置，再从后往前遍历找到第一个大于i的位置j，交换i,j,并将i+1之后的所有元素逆转
*/
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1)
			return;
		int i = len - 2;
		for (; i >= 0; i--) {
			if (nums[i] < nums[i + 1])
				break;
		}
		if (i < 0) {
			sort(nums.begin(), nums.end());
			for (auto a : nums)
				cout << a << " ";
			cout << endl;
			return;
		}
		int j = len - 1;
		for (; j >= 0; j--) {
			if (nums[j] > nums[i])
				break;
		}
		swap(nums[i], nums[j]);
		reverse(nums.begin() + i + 1, nums.end());

		for (auto a : nums)
			cout << a << " ";
		cout << endl;
	}
};


int main()
{
	freopen("in.txt", "r", stdin);
	string line;
	Solution sol;
	while (getline(cin, line)) {
		vector<int> nums;
		stringstream ss(line);
		string temp;
		while (getline(ss, temp, ',')) {
			nums.push_back(stoi(temp));
		}
		sol.nextPermutation(nums);
	}
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
