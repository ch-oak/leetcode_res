// 54. Spiral Matrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//Tag:

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		int num = matrix.size()*matrix.size();
		int row_start = 0;
		int row_end = row - 1;
		int col_start = 0;
		int col_end = col - 1;
		vector<int> ret;
		ret.reserve(num);
		while (row_start <= row_end && col_start <= col_end) {
			for (int i = col_start; i <= col_end; i++)
				ret.push_back(matrix[row_start][i]);
			row_start++;
			for (int i = row_start; i <= row_end; i++)
				ret.push_back(matrix[i][col_end]);
			col_end--;
			if (row_start > row_end || col_start > col_end)
				break;
			for (int i = col_end; i >= col_start; i--)
				ret.push_back(matrix[row_end][i]);
			row_end--;
			if (row_start > row_end || col_start > col_end)
				break;
			for (int i = row_end; i >= row_start; i--)
				ret.push_back(matrix[i][col_start]);
			col_start++;
		}
		return ret;
	}
};

int main()
{
	vector<vector<int>> matrix{ {3},{2} };
	auto res = Solution().spiralOrder(matrix);
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
