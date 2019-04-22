// 76. Minimum Window Substring.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

/**
*双指针，right找到包含所有字符的子串，然后使用left来收缩。
*使用hash表来判断是否找全和是否结束收缩。
*/

class Solution {
public:
	string minWindow(string s, string t) {
		if (s.empty() || t.empty())
			return "";
		int left = 0,cnt = 0;
		string res = "";
		unordered_map<char, int> letterCnt;
		int minLen = INT_MAX;
		for (char c : t) ++letterCnt[c];//letterCnt[c]调用后letterCnt就为0
		for (int right = 0; right < s.size(); right++) {
			if (--letterCnt[s[right]]>= 0)//t中的元素为0或正数，非t中的元素为负数 
				++cnt;
			if (cnt == t.size())
				cout << endl;
			while (cnt == t.size()) {
				if (minLen > right - left + 1) {
					minLen = right - left + 1;
					res = s.substr(left, minLen);
				}
				if (++letterCnt[s[left]] > 0) 
					--cnt;
				left++;
			}
		}
		return res;
	}
};

int main()
{
	string S = "ADOBECODEBANC", T = "ABC";
	cout << Solution().minWindow(S, T);
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
