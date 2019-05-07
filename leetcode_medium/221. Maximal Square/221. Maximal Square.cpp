// 221. Maximal Square.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//矩阵中由1组成的最大正方形
//Tag:Dynamic Programming

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//由矩阵存储前置状态,到有两个vector存储，再到有一个vector存储
//https://leetcode.com/problems/maximal-square/discuss/61803/C%2B%2B-space-optimized-DP
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int height = matrix.size();
		if (height == 0)
			return 0;
		int width = matrix[0].size();
		vector<vector<int>> dp(height, vector<int>(width, 0));//dp表示以(i,j)为右下角，最大正方形
		int result = 0;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (matrix[i][j] == '1') {
					dp[i][j] = 1;
					if (i > 0 && j > 0) {
						dp[i][j] += min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);//关键是状态转移方程
					}
					result = max(dp[i][j], result);
				}
			}
		}
		return result * result;
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
