// 47. Permutations II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>


/**
*解法1:先用简单的方法做，照搬46题回溯的做法，使用set存储可能出现的重复的情况。
*/
using namespace std;
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		set<vector<int>> res;
		vector<int> temp;
		vector<int> visited(nums.size(), 0);
		backtracking(nums, visited, res, temp);
		vector<vector<int>> vec_res(res.begin(),res.end());
		return vec_res;
		
	}
private:
	void backtracking(vector<int>& nums, vector<int> &visited,set<vector<int>> &res, vector<int> &temp) {
		if (temp.size() == nums.size()) {
			res.insert(temp);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				temp.push_back(nums[i]);
				backtracking(nums, visited, res, temp);
				temp.pop_back();
				visited[i] = 0;
			}
		}

	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	string line;
	while (getline(cin,line)) {
		stringstream ss(line);
		string temp;
		vector<int> nums;
		while (getline(ss, temp, ','))
			nums.push_back(stoi(temp));
		auto res = Solution().permuteUnique(nums);
		for (auto vec : res) {
			for (auto v : vec)
				cout << v << " ";
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
