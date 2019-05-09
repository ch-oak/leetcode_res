// 279. Perfect Squares.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/perfect-squares/
//和为目标的平方数的最少数目
//Tag:Math DP BFS

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//动态规划
class Solution {
public:
	int numSquares(int n) {
		vector<int> memo(n + 1, INT_MAX);
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		memo[0] = 0;
		memo[1] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j*j <= i; j++) {
				memo[i] = min(memo[i], memo[i - j * j] + 1);//对于i，一定是i-j*j和j*j之和，循环找到最合适的j
			}
		}
		return memo[n];
	}
};


//参考：https://leetcode.com/problems/perfect-squares/discuss/71488/Summary-of-4-different-solutions-(BFS-DP-static-DP-and-mathematics)
int main()
{
	Solution().numSquares(12);
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
