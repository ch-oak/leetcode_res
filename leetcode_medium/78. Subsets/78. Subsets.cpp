// 78. Subsets.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/subsets/submissions/
//给出一组数（无重复数字）的所有子集
//Tag: Array Backtracking Bit Manipulation;

#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


//类似77题的回溯
class Solution1 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		res.push_back({});
		if (nums.empty())
			return res;
		sort(nums.begin(),nums.end());
		int sz = nums.size();
		for (int i = 1; i <= sz; i++) {
			vector<int> temp;
			dfs(res, nums, temp, 0, i);
		}
		return res;
	}
private:
	void dfs(vector<vector<int>> &res, vector<int> &nums, vector<int> &temp, int index,int len) {
		if (temp.size() == len) {
			res.push_back(temp);
			return;
		}

		for (int i = index; i < nums.size(); i++) {
			temp.push_back(nums[i]);//先放一个数字在到后面挑，装满后放出元素，再到这个元素的后面去挑选元素。
			dfs(res, nums, temp,i + 1, len);
			temp.pop_back();
		}
	}
};

/**
*位操作
*/
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		
		if (nums.empty())
			return {};
		int len = nums.size();
		int total = 1 << len;
		vector<vector<int>> res(total);
		for (int i = 0; i < total; i++) {
			vector<int> temp;
			for (int j = 0; j < len; j++) {
				if ((1 << j) & i)
					temp.push_back(nums[j]);
			}
			res[i] = temp;
		}
		return res;
	}
};

int main()
{
	

	vector<int> nums = { 1,2,3 };
	auto res = Solution().subsets(nums);
	for (auto vec : res) {
		for (auto v : vec) {
			cout << v << " ";
		}
		cout << endl;
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
