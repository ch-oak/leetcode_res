// 16. 3Sum Closest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//在一组数中找到和与目标最接近的三个数的和

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

/**
*使用与15.3sum 相同的思路
*如果差异绝对值打k左移，差异绝对值小j右移
*/

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int len = nums.size();
		sort(nums.begin(), nums.end());
		int cha_old = INT_MAX;
		int res = 0;
		for (int i = 0; i < len - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int j = i + 1, k = len - 1;
			int temp = target - nums[i];
			while (j < k) {
				int sum = nums[j] + nums[k];
				int cha = temp - sum;
				if (cha > 0) {
					if (cha < cha_old) {
						res = sum + nums[i];
						cha_old = cha;
					}
					while (j < k&&nums[j] == nums[j + 1]) j++;//注意对相同数字的判断
					j++;
				}
				else if (cha < 0) {
					if (-cha < cha_old) {
						res = sum + nums[i];
						cha_old = -cha;
					}
					while (j < k&&nums[k] == nums[k - 1]) k--;
					k--;
				}
				else
					return sum + nums[i];
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
	int target;
	while (getline(cin, line)&&cin>>target) {
		stringstream ss(line);
		vector<int> nums;
		string temp;
		while (getline(ss, temp, ',')) 
			nums.push_back(stoi(temp));
		cout << "test" << endl;
		cout << s.threeSumClosest(nums, target);


	}
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
