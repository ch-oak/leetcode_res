// 6. ZigZag Conversion.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>


using namespace std;

/**
*参考https://leetcode.com/problems/zigzag-conversion/discuss/3435/If-you-are-confused-with-zigzag-patterncome-and-see!的说明和代码
*每一行字符下标的变化是2numRows-2i-2和2i,需要考虑s的长度比numRows小、s为空、numRows为1的情况，直接返回s.
*/
class Solution {
public:
	string convert(string s, int numRows) {
		int len = s.size();
		string res(len,' ');
		int pos = -1;
		for (int i = 0; i < numRows; i++) {
			pos++;
			if (i < len)
				res[pos] = s[i];
			int step1 = 2 * numRows - 2 - 2 * i;
			int step2 = 2 * i;
			int s_pos = i;
			while (1) {
				s_pos += step1;
				if (step1){
					if (s_pos < len) {
						pos++;
						res[pos] = s[s_pos];				
					}
					else
						break;
				}
				s_pos += step2;
				if (step2) {
					if (s_pos < len) {
						pos++;
						res[pos] = s[s_pos];		
					}
					else
						break;
				}
			}
		}
		return res;
	}
};
int main()
{
	freopen("in.txt", "r", stdin);
	string s;
	int numRows;
	Solution sol;
	while (cin >> s >> numRows) {
		cout << sol.convert(s, numRows) << endl;
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
