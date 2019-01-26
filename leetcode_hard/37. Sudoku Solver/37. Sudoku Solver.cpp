// 37. Sudoku Solver.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//解数独，使得9×9的表格中，每行，每列，每个block中的数字不重复
//Tag: HashTable BackTracking

#include "pch.h"
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/**
*参考：https://leetcode.com/problems/sudoku-solver/discuss/15752/Straight-Forward-Java-Solution-Using-Backtracking
使用回溯法
*/

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		if (board.empty())
			return;
		solve(board);
	}
private:
	bool solve(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') {
					for (char c = '1'; c <= '9'; c++) {
						if (isValid(board, c, i, j)) {
							board[i][j] = c;
							if (solve(board))
								return true;
							else
								board[i][j] = '.';
						}
					}
					return false;
				}
			}
		}
		return true;
	}
	bool isValid(vector<vector<char>>& board,char c,int row,int col) {
		for (int i = 0; i < 9; i++) {
			if (board[row][i] != '.'&&board[row][i] == c) return false;//检查行
			if (board[i][col] != '.'&&board[i][col] == c) return false;//检查列
			if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != '.'&&
				board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;//检查block
		}
		return true;
	}
};

int main()
{
	vector<vector<char>> board = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
	Solution().solveSudoku(board);
	for (auto vec : board) {
		for (auto v : vec)
			cout << v << " ";
		cout << endl;
	}
}
