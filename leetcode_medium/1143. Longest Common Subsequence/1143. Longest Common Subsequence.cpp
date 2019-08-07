// 1143. Longest Common Subsequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/longest-common-subsequence/
//最长公共子序列
//Tag:DP

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//最长公共子串，res[i][j]对应的是以i,j作为子串尾元素的最长子串，并不是前i个字母，text2前j个字母的最长子串
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int rows = text1.size();
		int cols = text2.size();
		vector<vector<int>> res(rows + 1, vector<int>(cols + 1, 0));//增加一行0和一列0来处理边界
		for (int i = 1; i <= rows; i++) {
			for (int j = 1; j <= cols; j++) {
				if (text1[i - 1] == text2[j - 1]) {//res[i][j]对应以text1前i个字母，text2前j个字母的最长公共序列
					res[i][j] = res[i - 1][j - 1] + 1;
				}
				else {
					res[i][j] = max(res[i - 1][j], res[i][j - 1]);
				}
			}
		}
		return res[rows][cols];
	}
};
int main()
{
	string text2 = "def";
	string text1 = "abc";
	cout<<Solution().longestCommonSubsequence(text1, text2);
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
