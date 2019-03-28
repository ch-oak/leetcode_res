// 52. N-Queens II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//N*N的棋盘里放N个棋子，没有两个棋子放在一列一行或对角线上有几种放法

#include "pch.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;
/**
*深度优先搜索，参考：https://leetcode.com/problems/n-queens-ii/discuss/20077/C%2B%2B-solution-DFS-easy-understanding
*注意当dfs传递引用时，递归完成后需要将引用还原
*使用positive[row+col]表示斜线上的棋子，使用positive[row+n-col-1]表示反斜线上的棋子
*/
class Solution {
public:
	int totalNQueens(int n) {
		vector<bool> col(n,true);
		vector<bool> positive(2 * n, true);
		vector<bool> negative(2 * n, true);
		int row = 0;
		int count = 0;
		dfs(row, col, positive, negative,count);

		return count;
	}
private:
	void dfs(int row,vector<bool> col,vector<bool> &positive, vector<bool> &negative,int &count) {
		if (row == col.size()) {
			count++;
			return;
		}
		for (int i = 0; i < col.size(); i++) {
			if (col[i] && positive[i+row] && negative[row + col.size()-i-1]) {
				col[i] = positive[i + row] = negative[row + col.size() - i - 1] = false;
				dfs(row + 1, col, positive, negative, count);
				col[i] = positive[i + row] = negative[row + col.size() - i + -1] = true;
			}
		}
	}
};


int main()
{
	cout << Solution().totalNQueens(4);
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
