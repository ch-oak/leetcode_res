// 73. Set Matrix Zeroes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

/**
*更好的方法，将结果存储在第一行和第一列
*https://leetcode.com/problems/set-matrix-zeroes/discuss/26014/Any-shorter-O(1)-space-solution
*/
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		set<int> zero_rows;
		set<int> zero_cols;
		if (matrix.empty())
			return;
		int rows = matrix.size();
		int cols = matrix[0].size();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (matrix[i][j] == 0)
					zero_rows.insert(i),zero_cols.insert(j);
			}
		}
		for (auto row : zero_rows) {
			for (int j = 0; j < cols; j++)
				matrix[row][j] = 0;
		}
		for (auto col : zero_cols) {
			for (int i = 0; i < rows; i++)
				matrix[i][col] = 0;
		}
	}
};

int main()
{
	vector<vector<int>> matrix{ {1,1,1},{1,0,1},{1,1,1} };
	Solution().setZeroes(matrix);
	for (auto vec : matrix) {
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
