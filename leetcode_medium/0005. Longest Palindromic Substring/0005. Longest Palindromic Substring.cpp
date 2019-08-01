// 0005. Longest Palindromic Substring.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/longest-palindromic-substring/
//最长回文子串
//Tag:String DP


#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

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
    std::cout << "Hello World!\n"; 
}

