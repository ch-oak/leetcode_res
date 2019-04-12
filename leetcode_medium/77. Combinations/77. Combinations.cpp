﻿// 77. Combinations.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/combinations/submissions/
//从1到n中取k的数的排列组合
//Tag:BackTracking

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
	vector<vector<int>> combine(int n, int k) {
		if (n == 0 || k == 0)
			return {};
		len = k;
		last = n;
		vector<vector<int>> res;
		vector<int> temp;
		dfs(1, res, temp);
		return res;
	}
private:
	int len;
	int last;
	void dfs(int index, vector<vector<int>>& res, vector<int> &temp) {
		if (temp.size() == len) {
			res.push_back(temp);
			return;
		}
		for (int i = index; i <= last; i++) {
			temp.push_back(i);
			dfs(i + 1, res, temp);
			temp.pop_back();
		}
	}
};
int main()
{
	auto res = Solution().combine(4, 2);
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
