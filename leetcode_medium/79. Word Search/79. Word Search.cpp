// 79. Word Search.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/word-search/
//在一个字符矩阵里查找给定的字符串，可以水平或者垂直邻接，但是不能重复
//Tag: Array Backtracking


#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

//回溯：https://blog.csdn.net/sysu_xiandan/article/details/78962137
/**
*找到结果如何从深层的调用中返回? 答：建立一个bool变量逐层返回。
*/
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty())
			return false;
		row_ = board.size();
		col_ = board[0].size();
		vector<vector<bool>> visited(row_, vector<bool>(col_, false));//新建vector是很费时间的，如果写在循环里会超时
		for (int i = 0; i < row_; i++) {
			for (int j = 0; j < col_; j++) {
				
				if (find(board, word, i, j, 0, visited))
					return true;
			}
		}
		return false;
	}
private:
	int row_;
	int col_;
	bool find(vector<vector<char>>& board, string &word, int row, int col,int depth,vector<vector<bool>>& visited) {
		if (depth == word.size())
			return true;//找到之后怎么跳出堆栈呢？
		if (row < 0 || col < 0 || row >= row_ || col >= col_)
			return false;
		if (board[row][col] != word[depth])
			return false;
		if (visited[row][col])
			return false;
		visited[row][col] = true;
		bool result = find(board, word, row + 1, col, depth + 1, visited) || find(board, word, row, col + 1, depth + 1, visited)
			|| find(board, word, row - 1, col, depth + 1, visited) || find(board, word, row, col - 1, depth + 1, visited);//建立一个变量一层一层的返回
		visited[row][col] = false;
		return result;
	}
};
int main()
{
	vector<vector<char>> board{ {'a'} };
	string word = "ab";
	Solution().exist(board,word);
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
