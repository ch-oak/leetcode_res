// 14. Longest Common Prefix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

/**
*用最简单的思路实现了，找出最短的字符串，逐个比较字符串。但许多边界地方没考虑完全，空容器，容器中只有一个字符串的情况。
*时间复杂度为O(n*m)
*/

class Solution1 {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())//容器为空
			return "";
		int len = strs.size();
		if (len == 1)
			return strs[0];
		string shortest_str = *min_element(strs.begin(), strs.end(), 
			[](const string &str1, const string &str2) {return str1.size() < str2.size(); });
		int min_len = shortest_str.size();
		int res_len = 0;
		bool flag = true;
		while (flag) {
			int i;
			for (i = 0; i < len - 1; i++) {
				if (res_len >= min_len || strs[i][res_len] != strs[i + 1][res_len]) {
					flag = false;
					break;
				}
			}
			if (i == len - 1)//所有字符串res_len位置的字符都相同才自增自己
				res_len++;
		}
		return shortest_str.substr(0,res_len);
	}
};


/**
*参考：https://leetcode.com/problems/longest-common-prefix/discuss/6910/Java-code-with-13-lines
*不断减小前缀字符的数目。
*/
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())//容器为空
			return "";
		string pre = strs[0];
		int i = 1, len = strs.size();
		while (i < len && !pre.empty()) {
			while (strs[i].find(pre) != 0)
				pre = pre.substr(0, pre.size() - 1);
			i++;
		}
		return pre;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	string str;
	Solution sol;
	while (getline(cin, str)) {
		vector<string> strs;
		stringstream ss(str);
		string temp;
		while (getline(ss, temp, ','))
			strs.push_back(temp);
		cout << sol.longestCommonPrefix(strs) << endl;

	}
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
