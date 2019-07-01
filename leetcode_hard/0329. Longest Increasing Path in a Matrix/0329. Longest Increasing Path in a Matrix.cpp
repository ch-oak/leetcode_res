// 0329. Longest Increasing Path in a Matrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//矩阵中的最长递增路径
//DFS Topologicalsort Memorization
//Hard
//给一个给定整数矩阵，找出里面的最长增长序列的长度，只能上下左右移动。
//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/


#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

/**
*使用深度优先搜索加记忆的动态规划
*pull（拉取）：提取远程库，合并到本地
*fetch(提取）：提取远程库，不合并
*参考：https://leetcode.com/problems/longest-increasing-path-in-a-matrix/discuss/78317/C%2B%2B-DP-DFS-solution-sharing
*/

class Solution {
public:
	int longestIncreasingPath(vector <vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return 0;
		int rows = matrix.size(), cols = matrix[0].size();
		vector<vector<int>> dp(rows, vector<int>(cols, 0));
		vector<vector<int>> dirs = { {-1,0},{1,0},{0,-1},{0,1} };
		int res = -1;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++)
				res = max(res, dfs(matrix, dp, dirs, rows, cols, i, j));
		}
		return res;
	}
private:
	int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, vector<vector<int>> &dirs, int &rows, int &cols, int x, int y) {
		if (dp[x][y] > 0) return dp[x][y];
		for (auto dir : dirs) {
			int xx = x + dir[0], yy = y + dir[1];
			if (xx < 0 || xx >= rows || yy < 0 || yy >= cols) continue;
			if (matrix[xx][yy] <= matrix[x][y]) continue;
			dp[x][y] = max(dp[x][y], dfs(matrix, dp, dirs, rows, cols, xx, yy));
		}
		return ++dp[x][y];//将x,y加入路径
	}
};
int main()
{
	freopen("in.txt", "r", stdin);
	string line;
	vector<vector<int>> matrix;
	while (getline(cin, line)) {
		stringstream ss(line);
		string temp;
		vector<int> row;
		while (getline(ss, temp, ','))
			row.push_back(stoi(temp));
		matrix.push_back((row));
	}
	Solution sl;
	cout << sl.longestIncreasingPath(matrix);
}
