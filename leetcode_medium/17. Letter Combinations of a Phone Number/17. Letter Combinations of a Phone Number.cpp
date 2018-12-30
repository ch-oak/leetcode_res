// 17. Letter Combinations of a Phone Number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//每个数字代表某些字母中的一个，给出串数字，找出所有可能性

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/**
*一个比较简单的方法，绘制发散图可以发现，有几个数字就有几层，每一层都是按照一定规律重复的在排列对应层数字所代表的字母
*重复的次数是该层之后除最后一层的所有层数字代表字母数的乘积
*直接全部排出来就是了。直观的想法。。。。。。
*复杂度应该是O(N）吧，时间主要浪费在map上了。
*/

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty())
			return {};
		unordered_map<char, string> phone = { {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };
		int len = 1;
		int digits_len = digits.size();
		vector<int> repeat(digits_len,1);
		for (int i = digits_len - 1; i >= 0; i--) {
			int temp = phone[digits[i]].size();
			len *= temp;
			if (i < digits_len - 1)
				repeat[i] = repeat[i + 1] * phone[digits[i+1]].size();
		}	
		vector<string> res(len);
		for (int i = 0; i < digits.size(); i++) {
			string alph = phone[digits[i]];
			int this_size = alph.size();
			int step = repeat[i] * this_size;
			for (int j = 0; j < len; j += step) {
				int trans = 0;
				for (int k = 0; k < step; k += repeat[i]) {
						char c = alph[trans%this_size];
						for (int m = 0; m < repeat[i]; m++) {
							res[j + k + m] += c;
						}
						trans++;
				}
			}
		}
		return res;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	string digits;
	Solution s;
	while (cin >> digits) {
		auto res = s.letterCombinations(digits);
		for (auto a : res)
			cout << a << " " << endl;
		cout << endl;
	}
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
