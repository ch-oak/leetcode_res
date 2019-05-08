// 240. Search a 2D Matrix II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//有序矩阵找数
//https://leetcode.com/problems/search-a-2d-matrix-ii/
//Tag:BiNary_Search  Divide_and_Conque

#include "pch.h"
#include <iostream>
#include <vector>



using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;
		int rows = matrix.size();
		int cols = matrix[0].size();
		int up = 0, down = rows - 1;
		while (down < up) {
			int mid = (up + down) / 2;
			if (matrix[mid][0] == target) return true;
			else if (matrix[mid][0] < target) down = mid + 1;
			else up = mid - 1;
		}
		for (int i = 0; i <= down; i++) {
			int left = 0, right = cols - 1;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (matrix[i][mid] == target) return true;
				else if (matrix[i][mid] < target) left = mid + 1;
				else right = mid - 1;
			}
		}
		return false;
	}
};

int main()
{

	vector<vector<int>> matrix{ {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} };
	cout << Solution().searchMatrix(matrix,5);
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
