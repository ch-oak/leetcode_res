// 18. 4Sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//找出一组数中四数之和为指定值的所有组合

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/**
*套用3-sum的解法，又加了一层循环
*/
class Solution {
public:
	vector < vector<int>> fourSum(vector<int>& nums, int target) {
		vector < vector<int>> res;
		int len = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i < len - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			for (int j = i + 1; j < len - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1])
					continue;
				int left = j + 1;
				int right = len - 1;
				int resual = target - nums[i] - nums[j];
				while (left < right) {
					if (nums[left] + nums[right] == resual) {
						res.push_back({ nums[i],nums[j] ,nums[left],nums[right] });
						while (left < right&&nums[left++] == nums[left]);//这里的比较很有意思，left++，左边是原来的，右边是递增之后的。
						while (left < right&&nums[right--] == nums[right]);
					}
					else if (nums[left] + nums[right] > resual) {
						while (left < right&&nums[right--] == nums[right]);	
					}
					else {
						while (left < right&&nums[left++] == nums[left]);
					}
				}
			}
		}

		return res;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	string line;
	Solution s;
	while (getline(cin , line)) {
		vector<int> nums;
		stringstream ss(line);
		string temp;
		while (getline(ss, temp, ','))
			nums.push_back(stoi(temp));
		int target;
		cin >> target;
		auto res = s.fourSum(nums, target);
		for (auto vec : res) {
			for (auto a : vec)
				cout << a << " " ;
			cout << endl;
		}
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
