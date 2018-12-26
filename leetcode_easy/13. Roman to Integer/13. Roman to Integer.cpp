// 13. Roman to Integer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>



using namespace std;

/**
*比较简单的思路，如果遇到IV,IX之类的就将I置为负数，否则逐个累加。
*/
class Solution1{
public:
	int romanToInt(string s ){
		int res = 0;
		unordered_map<char, int> list{ {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
		int len = s.size();
		for (int i = 0; i < len; i++) {
			if (s[i] == 'I'&& i + 1 < len && (s[i + 1] == 'V' || s[i + 1] == 'X'))
				res += -list[s[i]];
			else if (s[i] == 'X'&& i + 1 < len && (s[i + 1] == 'L' || s[i + 1] == 'C'))
				res += -list[s[i]];
			else if (s[i] == 'C'&& i + 1 < len && (s[i + 1] == 'D' || s[i + 1] == 'M'))
				res += -list[s[i]];
			else
				res += list[s[i]];
		}
		return res;
	}
};

/**
*比较聪明的办法，从后往前累加，如果前一个数字小于后一个数字，则出现4,9,40，90等情况
*/
class Solution2 {
public:
	int romanToInt(string s) {
		int res = 0;
		unordered_map<char, int> list{ {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
		res += list[s.back()];
		int len = s.size();
		for (int i = len-2; i >= 0; i--) {
			if (list[s[i]] < list[s[i + 1]])
				res -= list[s[i]];
			else
				res += list[s[i]];
		}
		return res;
	}
};

/**
*从前往后也可以，注意越界，出现两个字符组成一个数字的时候，前一个字符一定比后面的小。
*/
class Solution {
public:
	int romanToInt(string s) {
		int res = 0;
		unordered_map<char, int> list{ {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
		int len = s.size();
		for (int i = 0; i < len; i++) {
			int temp = list[s[i]];
			if (i < len - 1) {
				if (list[s[i]] < list[s[i + 1]])
					temp = -temp;
			}
			res += temp;
		}
		return res;
	}
};
int main()
{
	freopen("in.txt", "r", stdin);
	string temp;
	Solution sol;
	while (cin >> temp) {
		cout << sol.romanToInt(temp) << endl;
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
