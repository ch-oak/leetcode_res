// 44. Wildcard Matching.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//通配符匹配。其中模式串中可以包含‘?’和‘*’，‘?’可以匹配单个任意字符，‘*’可以匹配任意字符串（包括空串）

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

/**
*https://blog.csdn.net/qq_29592167/article/details/83114404
*/
class Solution {
public:
	bool isMatch(string s, string p) {
		int sindex = 0, pindex = 0, sstart = 0, pstart = 0;
		while (sindex < s.size()) {
			if (s[sindex] == p[pindex] || p[pindex] == '?')
				sindex++, pindex++;
			else if (p[pindex] == '*')
				sstart = sindex, pstart = ++pindex;
			else if (pstart)//与'*'情况对称
				sindex = ++sstart, pindex = pstart;
			else
				return 0;
		}
		while (pindex < p.size() && p[pindex] == '*')
			++pindex;
		return pindex == p.size();
	}
};
int main()
{
	Solution().isMatch("aa", "*");
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
