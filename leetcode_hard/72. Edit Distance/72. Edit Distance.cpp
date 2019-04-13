// 72. Edit Distance.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/edit-distance/
//编辑距离，将一个字符串变成另一个字符串的最短操作

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {

		int len1 = word1.size();
		int len2 = word2.size();
		if (word1.empty() || word2.empty())
			return len1 + len2;
		vector<vector<int>> dp(len1+1, vector<int>(len2+1,0));
		for (int i = 0; i <= len1; i++) dp[i][0] = i;
		for (int j = 0; j <= len2; j++) dp[0][j] = j;
		for (int i = 1; i <= len1; i++) {
			for (int j = 1; j <= len2; j++) {
				int replace;
				if (word1[i - 1] == word2[j - 1])//如果word1的第i个数和word2的第j个数相同
					replace = dp[i - 1][j - 1];
				else
					replace = dp[i - 1][j - 1] + 1;
				int ins_del = min(dp[i][j - 1], dp[i - 1][j]) + 1;
				dp[i][j] = min(replace, ins_del);
			}
		}
		//for (auto vec : dp) {
		//	for (auto v : vec) {
		//		cout << v << " ";
		//	}
		//	cout << endl;
		//}
		return dp[len1][len2];
	}
};

int main()
{
	string word1 = "horse", word2 = "ros";
	cout << Solution().minDistance(word1, word2);

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
