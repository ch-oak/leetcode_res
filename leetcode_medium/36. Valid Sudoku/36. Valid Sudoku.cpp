﻿// 36. Valid Sudoku.cpp : 此文件包含 'main' 函数。程序执行将在此处开始并结束。
//判断一个9*9的格子中每一行，每一列，9个3×3子表格中是否有重复的格子

#include "pch.h"
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

/**
*解法1：用一个vector记录每一行或者每一列或者子表格中的元素，如果出现重复元素返回错误。很笨的遍历方法。跑了5次循环。
*/

class Solution1 {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			vector<int> row(10);
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.')
					continue;
				int temp = board[i][j] - '0';
				if (row[temp] == 1)
					return false;
				else
					row[temp] = 1;
			}
		}
		for (int i = 0; i < 9; i++) {
			vector<int> col(10);
			for (int j = 0; j < 9; j++) {
				if (board[j][i] == '.')
					continue;
				int temp = board[j][i] - '0';
				if (col[temp] == 1)
					return false;
				else
					col[temp] = 1;
			}
		}
		for (int num = 0; num < 3; num++) {
			vector<int> sub(10);
			int i = num * 3;
			int i_end = i + 3;
			for (; i < i_end; i++) {
				for (int j = 0; j < 3; j++) {
					if (board[i][j] == '.')
						continue;
					int temp = board[i][j] - '0';
					if (sub[temp] == 1)
						return false;
					else
						sub[temp] = 1;
				}
			}
		}

		for (int num = 0; num < 3; num++) {
			vector<int> sub(10);
			int i = num * 3;
			int i_end = i + 3;
			for (; i < i_end; i++) {
				for (int j = 3; j < 6; j++) {
					if (board[i][j] == '.')
						continue;
					int temp = board[i][j] - '0';
					if (sub[temp] == 1)
						return false;
					else
						sub[temp] = 1;
				}
			}
		}

		for (int num = 0; num < 3; num++) {
			vector<int> sub(10);
			int i = num * 3;
			int i_end = i + 3;
			for (; i < i_end; i++) {
				for (int j = 6; j < 9; j++) {
					if (board[i][j] == '.')
						continue;
					int temp = board[i][j] - '0';
					if (sub[temp] == 1)
						return false;
					else
						sub[temp] = 1;
				}
			}
		}
		return true;
	}
	
};

/**
*参考：https://leetcode.com/problems/valid-sudoku/discuss/15472/Short%2BSimple-Java-using-Strings
*解法2：用set记录每个数字在哪一行，哪一列，哪一个block
*记录block的有点厉害，直接i,j都除以3就将block编码了
*新学到的东西：c++里，char int类型均不能转换为string
*char可以使用push_back压入stringint要使用to_string函数
*无序容器的插入是范围一个pair,first是迭代器，second是true或者false表示插入还是未插入
*/

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		unordered_set<string> container;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					string temp;
					temp.push_back(board[i][j]);
					if (!container.insert(temp + " in row" + to_string(i)).second ||
						!container.insert(temp + " in col" + to_string(j)).second ||
						!container.insert(temp + "in block" + to_string(i / 3) +"&" + to_string(j / 3)).second)
						return false;
				}
			}
		}
		return true;
	}
};

int main()
{
	int i = 1;
	cout << "test" + to_string(i) << endl;
	vector<vector<char>> board = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };

	cout << Solution().isValidSudoku(board);
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
