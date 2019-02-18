// 48. Rotate Image.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//将n*n的矩阵顺时针旋转90°
//Tag:

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/**
*参考：https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image
*/
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		reverse(matrix.begin(), matrix.end());
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = i + 1; j < matrix[i].size(); j++)
				swap(matrix[i][j], matrix[j][i]);
		}
	}
};


int main()
{
	
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
