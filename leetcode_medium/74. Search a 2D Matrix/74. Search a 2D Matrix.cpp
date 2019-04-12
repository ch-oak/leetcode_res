// 74. Search a 2D Matrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//在有序矩阵(每一行递增，本行开头大于上一行结尾）查找指定元素
//Tags:Array Binary Search

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		
		if (matrix.empty() || matrix[0].empty())
			return false;
		row = matrix.size();
		col = matrix[0].size();
		target_row = find_row(matrix, target);
		if (target_row == -1)
			target_row++;
		return find(matrix,target)>=0;
	}
private:
	int row, col,target_row;
	int find_row(vector<vector<int>>& matrix, int target) {//找到目标行
		int left = 0, right = row;
		
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (matrix[mid][0] == target) return mid;
			if (matrix[mid][0] < target) left = mid + 1;
			else right = mid;
		}
		return left-1;
	}
	int find(vector<vector<int>>& matrix, int target) {//在目标行查找
		int left = 0, right = col;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (matrix[target_row][mid] == target) 
				return mid;
			else if (matrix[target_row][mid] < target) left = mid + 1;
			else right = mid;
		}
		return -1;
	}	
};

int main()
{
	vector<vector<int>> matrix{{1}};
	cout << Solution().searchMatrix(matrix, 1);
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
