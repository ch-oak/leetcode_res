// 0005. Longest Palindromic Substring.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//最长回文子串
//Tag:String DP
//Medium
//https://leetcode.com/problems/longest-palindromic-substring/

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

/*
首先枚举回文串的中心 ii，然后分两种情况向两边扩展边界，直到遇到不同字符为止:
回文串长度是奇数，则依次判断 s[i−k]==s[i+k],k=0,1,2,3,…
回文串长度是偶数，则依次判断 s[i−k]==s[i+k−1],k=1,2,3,…
*/
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty())
			return {};
		int len = s.size();
		string str;
		int res = 0;
		for (int i = 0; i < len; i++) {
			for (int j = 0; i - j >= 0 && i + j < len; j++)
				if (s[i - j] == s[i + j]) {
					if (res < 2 * j + 1) {
						res = 2 * j + 1;
						str = s.substr(i - j, 2 * j + 1);
					}
				}
				else
					break;
			for (int j = i, k = i + 1; j >= 0 && k < len; j--, k++)
				if (s[j] == s[k]) {
					if (res < k - j + 1) {
						res = res > k - j + 1 ? res : k - j + 1;
						str = s.substr(j, k - j + 1);
					}
				}
				else
					break;
		}
		return str;
	}
};

int main()
{
	char a = 'a';
	string str;
	str += a;
	cout << str << endl;
    std::cout << "Hello World!\n"; 
}

