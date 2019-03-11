// 46. Permutations.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给出一组不重复的数字的所有排列组合
//Tag:Backtracking

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

/**
*参考：https://leetcode.com/problems/permutations/submissions/
*还是回溯，不过需要用一个visited来记录选择的数字，如果已经选择了就跳过
*/
using namespace std;
class Solution1 {   
public:
	vector<vector<int>> permute(vector<int>& nums) {
		int len = nums.size();
		vector<vector<int>> res;
		vector<int> temp;
		vector<int> visited(len, 0);
		backtracking(res, visited, nums, temp, 0);
		return res;
	}
private:
	void backtracking(vector<vector<int>> &res, vector<int> &visited, vector<int> &nums, vector<int> &temp, int level) {
		if (level == nums.size()) {
			res.push_back(temp);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			//暴力递归，穷尽所有可能性
			if (visited[i] == 1)
				continue;
			visited[i] = 1;//①
			temp.push_back(nums[i]);//②
			backtracking(res, visited, nums, temp, level + 1);
			temp.pop_back();//②~
			visited[i] = 0;//①~
		}
	}
};
/**
*解法2：递归的和第一个位置的数字交换
*/
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		int len = nums.size();
		vector<vector<int>> res;
		backtracking(res, nums, 0);
		return res;
	}
private:
	void backtracking(vector<vector<int>> &res, vector<int> &nums, int beg) {
		if (beg == nums.size() - 1) {
			res.push_back(nums);
			return;
		}
		for (int i = beg; i < nums.size(); i++) {
			swap(nums[beg], nums[i]);
			backtracking(res, nums, beg + 1);
			swap(nums[beg], nums[i]);
		}
	}
};


int main()
{
	freopen("in.txt", "r", stdin);
	string line;
	while (getline(cin, line)) {
		stringstream ss(line);
		vector<int> nums;
		string temp;
		while (getline(ss, temp, ','))
			nums.push_back(stoi(temp));
		auto res = Solution().permute(nums);
		for (auto vec : res) {
			for (auto v : vec) {
				cout << v << " ";
			}
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
