// 63. Unique Paths II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
/**
*深度优先搜索，超时
*/
class Solution1 {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty())
			return 0;
		int res = 0;
		row_total = obstacleGrid.size();
		col_total = obstacleGrid[0].size();
		int row = 0;
		int col = 0;
		dfs(obstacleGrid, row, col, res);
		return res;
	}
private:
	int row_total;
	int col_total;
	void dfs(vector<vector<int>>& obstacleGrid, int row, int col, int& res) {
		if (row == row_total - 1 && col == col_total - 1)
			res++;
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				if (row + 1 <= row_total-1&&obstacleGrid[row + 1][col] != 1) {
					dfs(obstacleGrid, row+1, col, res);
				}	
			}
			if (i == 1) {
				if (col + 1 <= col_total - 1 && obstacleGrid[row][col + 1] != 1) {
					dfs(obstacleGrid, row, col + 1, res);
				}
			}

		}
	}
};
/**
*动态规划：https://leetcode.com/problems/unique-paths-ii/discuss/23252/4ms-O(n)-DP-Solution-in-C%2B%2B-with-Explanations
*/
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int row = obstacleGrid.size();
		int col = obstacleGrid[0].size();
		vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
		dp[0][1] = 1;//为到达左上角第一个点铺路，dp[1][0]=1应该也可以
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				if (!obstacleGrid[i-1][j-1])//注意obstacleGrid的大小与dp是不一样的，这里实质上是指i,j位置是可到达的。
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[row][col];
	}
};
int main()
{
	vector<vector<int>> obstacleGrid{ {1,0,0},{0,1,0},{0,0,0} };
	cout << Solution().uniquePathsWithObstacles(obstacleGrid) << endl;
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
