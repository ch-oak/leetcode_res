// 59. Spiral Matrix II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/***
*方法1：找规律，太复杂了
*/
class Solution1 {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ret(n,vector<int>(n));
		int k = 1, i = 0;
		while (k <= n*n) {
			int j = i;
			while (j < n - i)             // 1. horizonal, left to right
				ret[i][j++] = k++;
			j = i + 1;
			while (j < n - i)             // 2. vertical, top to bottom
				ret[j++][n - i - 1] = k++;
			j = n - i - 2;
			while (j > i)                  // 3. horizonal, right to left 
				ret[n - i - 1][j--] = k++;
			j = n - i - 1;
			while (j > i)                  // 4. vertical, bottom to  top 
				ret[j--][i] = k++;
			i++;
		}
		return ret;
	}
};

/**
*方法2：使用变量记录开始和结束的行和列
*/
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ret(n, vector<int>(n));
		int row_start = 0;
		int row_end = n - 1;
		int col_start = 0;
		int col_end = n - 1;
		int num = 1;
		while (num <= n * n) {
			//
			for (int i = col_start; i <= col_end; i++)
				ret[row_start][i] = num++;
			row_start++;
			//
			for (int i = row_start; i <= row_end; i++)
				ret[i][col_end] = num++;
			col_end--;
			//
			for (int i = col_end; i >= col_start; i--) {
				//if (row_start <= row_end)
					ret[row_end][i] = num++;
			}
			row_end--;
			//
			for (int i = row_end; i >= row_start; i--) {
				//if (col_start <= col_end)
					ret[i][col_start] = num++;
			}
			col_start++;
		}
		return ret;
	}
};

int main()
{
	auto ret = Solution().generateMatrix(4);
	for (auto vec : ret) {
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
