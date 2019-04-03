// 62. Unique Paths.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

/**
*递归：超时了
*/
class Solution1 {
public:
	int uniquePaths(int m, int n) {
		int res = 0;
		dfs(m, n, 0, 0, res);
		return res;
	}
private:
	void dfs(int &m,int &n,int row, int col,int &res) {
		if (row == m-1 && col == n-1)
			res++;
		if (row <= m - 1 && col <= n - 1) {
			for (int i = 0; i < 2; i++) {
				if(i==0)
					dfs(m, n, row + 1, col, res);
				if(i==1)
					dfs(m, n, row, col + 1, res);
			}
		}
	}
};

/**
*动态规划：https://leetcode.com/problems/unique-paths/discuss/22954/C%2B%2B-DP
*
*/
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, 1));//如果只有一行或者一列，那么dp[i][j]=1
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];//i,j位置的到达路径数为其左方和上方的到达路径之和。
			}
		}
		return dp[m - 1][n - 1];
	}
};

int main()
{
	cout << Solution().uniquePaths(3, 2);
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
