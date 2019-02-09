// 39. Combination Sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一组数和一个目标数，找出所有相加与目标数字相等的组合
//Tag:Array,BackTracking

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

/**
*解法1：简单的回溯，记录每个结果时候使用temp,但是没有pop_back
*参考：https://leetcode.com/problems/combination-sum/discuss/16496/Accepted-16ms-c%2B%2B-solution-use-backtracking-easy-understand.
*/
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> res;
		vector<int> temp;
		back_track(res,temp, candidates, target,0);
		return res;
	}

private:
	void back_track(vector<vector<int>> &res,vector<int> temp,vector<int>& candidates,int target,int begin) {
		if (target < 0)
			return;
		if (target == 0) {
			res.push_back(temp);
			return;
		}
		for (int i = begin; i < candidates.size(); i++) {
			if (candidates[i] > target)
				break;
			temp.push_back(candidates[i]);
			back_track(res, temp, candidates, target - candidates[i],i);
			temp.pop_back();//这句话没有想到
		}
		return;
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
		auto res = Solution().combinationSum(candidates, target);
		for (auto vec : res) {
			for (auto v : vec)
				cout << v << " ,";
			cout << endl;
		}
			
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
