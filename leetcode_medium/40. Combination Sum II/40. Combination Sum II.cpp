// 40. Combination Sum II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一组数字，每个数字可能出现多次，但只能使用一次，找出和为给定目标数字的所有组合

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

/**
*对39题略作修改
*/
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
        set <vector<int>> res;
		vector<int> temp;
		dfs(res, candidates, temp, target, 0);
		vector < vector<int>> res_vec(res.begin(), res.end());
		return res_vec;
	}
private:
	void dfs(set<vector<int>> &res, vector<int>& candidates,vector<int> temp, int target,int next) {
		if (target == 0)
			res.insert(temp);
		if (target < 0)return;
		for (int i = next; i < candidates.size(); i++) {
			temp.push_back(candidates[i]);
			dfs(res, candidates, temp, target - candidates[i],i+1);//不能重复就从下一个数字开始，使用set存储结果
			temp.pop_back();
		}
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	string line;
	while (getline(cin, line)) {
		vector<int> candidates;
		stringstream ss(line);
		string temp;
		while (getline(ss, temp, ','))
			candidates.push_back(stoi(temp));
		getline(cin, temp);
		int target = stoi(temp);
		auto res = Solution().combinationSum2(candidates, target);
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
