// 0072. Edit Distance.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//编辑距离
//https://leetcode.com/problems/edit-distance/
//Tag:String DP
//Hard

//编辑距离，将一个字符串变成另一个字符串的最少操作步骤，只允许插入，删除，替换

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//从尾巴往前推，word1变为word2是替换，插入或者删除三者操作中最少的
//dp[i][j]代表word1前i个字母转换为word2前j个字母的最少次数

//替换：尾巴相同dp[i][j] = d[i-1][j-1] 尾巴不同dp[i][j] = dp[i-1][j-1] + 1
//插入一个与word2尾巴相同的字符：dp[i][j-1] + 1
//删除word1的尾巴：dp[i-1][j]

class Solution {
public:
	int minDistance(string word1, string word2) {

		int len1 = word1.size();
		int len2 = word2.size();
		if (word1.empty() || word2.empty())
			return len1 + len2;
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 0; i <= len1; i++) dp[i][0] = i;
		for (int j = 0; j <= len2; j++) dp[0][j] = j;
		//dp[i][j]代表word1前i个字母转换为word2前j个字母的最少次数
		for (int i = 1; i <= len1; i++) {
			for (int j = 1; j <= len2; j++) {
				int replace;
				if (word1[i - 1] == word2[j - 1])//如果word1的第i个数和word2的第j个数相同
					replace = dp[i - 1][j - 1];
				else
					replace = dp[i - 1][j - 1] + 1;
				//在word1尾巴上插入一个与word2尾巴相同的字母
				//删除word1尾巴上的字母
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