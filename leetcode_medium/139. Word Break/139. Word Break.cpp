// 139. Word Break.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//按照给定的词典，能否将字符串分开
//Tag:

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//动态规划
//参考：https://blog.csdn.net/feliciafay/article/details/18999903
//从字符串的最后一个字符开始切割，如果前面的字符串可以切割，且之后的字符串在词典中，那么这个字符串也可以切割。
//从短到长的计算长度为i的字符串是否可以分割
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> res(s.size() + 1, false);
		res[0] = true;
		for (int i = 1; i < s.size() + 1; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (res[j] && find(wordDict.begin(),wordDict.end(),s.substr(j, i - j)) != wordDict.end()) {
					res[i] = true;
				}
			}
		}
		return res[s.size()];

	}
};

int main()
{
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
