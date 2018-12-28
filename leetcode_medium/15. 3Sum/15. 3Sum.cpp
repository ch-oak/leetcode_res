// 15. 3Sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//一组数中，三数之和为0的所有组合

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;
/**
*使用穷举法不出所料的超时了，即使做了排序，做了一些减枝
*参考：https://www.cnblogs.com/grandyang/p/4481576.html
*确定第一个数字后，从前从后找其余两个数字。同时对于相同的数字要跳过。
*/
class Solution {
public:
	vector < vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		int len = nums.size();
		sort(nums.begin(), nums.end());
		if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
		for (int i = 0; i < len - 2; i++) {
			if (nums[i] > 0)//第一个数字大于0就没意义了
				break;
			if (i > 0 && nums[i - 1] == nums[i])//重复数字跳过
				continue;
			//for (int j = i + 1; j < len - 1; j++) {
			//	if (nums[i] + nums[j] > 0)
			//		break;
			//	if (nums[i] + nums[j] + nums.back()<0)
			//		continue;
			//	for (int k = j + 1; k < len; k++) {
			//		if (nums[i] + nums[j] + nums[k] == 0)
			//			res.emplace(vector<int>{ nums[i],nums[j],nums[k] });
			//	}
			//}
			int j = i + 1, k = len - 1;
			int target = -nums[i];
			while (j < k) {
				if (nums[j] + nums[k] == target) {
					res.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
					while (j < k && nums[j] == nums[j + 1]) ++j;//重复数字跳过
					while (j < k && nums[k] == nums[k - 1]) --k;//重复数字跳过
					j++;
					k--;
				}
				else if (nums[j] + nums[k] > target)
					k--;
				else
				    j++;
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
	while (getline(cin, line)) {
		vector<int> nums;
		string temp;
		stringstream ss(line);
		while (getline(ss, temp, ',') )
			nums.push_back(stoi(temp));
		vector<vector<int>> res = s.threeSum(nums);
		for (auto vec : res) {
			for (auto a : vec)
				cout << a << " ";
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
