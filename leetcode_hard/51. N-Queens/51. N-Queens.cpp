// 51. N-Queens.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//n×n的格子上放n个皇后，不能相互攻击(任意两个皇后不在同一行，同一列，同一斜线上）
//Tags:Backtracking
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
*解法1：典型的回溯算法
*/

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		vector<string> nQueens(n, string(n, '.'));
		solveNQueens(res, nQueens, 0, n);
		return res;
	}
private:
	void solveNQueens(vector<vector<string>> &res, vector<string> &nQueens, int row, int n) {
		if (row == n) {
			res.push_back(nQueens);
			return;
		}
		for (int col = 0; col < n; col++) {
			if (isValid(nQueens, row, col, n)) {
				nQueens[row][col] = 'Q';
				solveNQueens(res, nQueens, row + 1, n);
				nQueens[row][col] = '.';
			}
		}
	}
	bool isValid(vector<string> &nQueens, int row, int col,int n) {
		for (int i = 0; i < row; i++)
			if (nQueens[i][col] == 'Q')
				return false;
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)//45度
			if (nQueens[i][j] == 'Q')
				return false;
		for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)//135度
			if (nQueens[i][j] == 'Q')
				return false;
		return true;
	}
};
int main()
{
	auto res = Solution().solveNQueens(4);
	for (auto vec : res) {
		for (auto v : vec)
			cout << v << " " << endl;
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
