// 200. Number of Islands.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一个由 '1'（陆地）和 '0'（水）组成的的二维矩阵，计算岛屿的数量。一个岛被水包围，
//并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。
//你假设网格的四个边均被水包围。
//Tag: Depth-first Search    Breadth-first Seartch    Union Find

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

/**
*dfs:暴力dfs,对每个为1的单元做四个方向的深度优先搜索，将1全部变为2（有变化则说明是一个孤岛)
*/
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())
			return 0;
		int res = 0;
		int row = grid.size(), col = grid[0].size();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int note = 0;
				
				dfs(grid, i, j,note);
				if (note != 0)
					res++;
			}
		}
		return res;
	}
private:
	void dfs(vector<vector<char>>& grid, int i, int j,int &note) {
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
			return;
		if (grid[i][j] == '2' || grid[i][j] == '0')
			return;
		else {
			grid[i][j] = '2';
			note++;
		}
		vector<pair<int, int>> dir{ {-1, 0}, { 1,0 }, { 0,-1 }, { 0,1 }};
		for (int n = 0; n < 4; n++) 
			dfs(grid, i+dir[n].first, j+dir[n].second,note);
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	string line;
	vector<vector<char>> grid;
	while (getline(cin, line)) {
		vector<char> temp(line.begin(), line.end());
		grid.push_back(temp);
	}
	cout << Solution().numIslands(grid);
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
