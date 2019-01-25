// 37. Sudoku Solver.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//解数独，使得9×9的表格中，每行，每列，每个block中的数字不重复

#include "pch.h"
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& borad) {
		
	}
private:

	bool isValidSudoku(vector<vector<char>>& board) {
		unordered_set<string> container;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					string temp;
					temp.push_back(board[i][j]);
					if (!container.insert(temp + " in row" + to_string(i)).second ||
						!container.insert(temp + " in col" + to_string(j)).second ||
						!container.insert(temp + "in block" + to_string(i / 3) + "&" + to_string(j / 3)).second)
						return false;
				}
			}
		}
		return true;
	}
};

int main()
{
	vector<vector<char>> board = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
	Solution().solveSudoku(board);
    std::cout << "Hello World!\n"; 
}
