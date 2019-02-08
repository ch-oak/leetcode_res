// 38. Count and Say.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//最初的数字为1，下一个数字为上一个数字的count,11,21,1211......

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/**
*最简单的做法，因为因为测试用例为1到30，直接将所有的测试结果都计算出来
*/
class Solution {
public:
	string countAndSay(int n) {
		vector<string> str(31);
		if (n == 1)
			return "1";
		str[1] = "1";
		for (int i = 2; i <= n; i++) {
			string temp = str[i - 1];
			str[i] = countSay(temp);
		}
		return str[n];
	}
private:
	string countSay(string &temp) {
		string res;
		int pre = 0;
		int i = 1;
		for (; i < temp.size(); i++) {
			if (temp[i] != temp[i - 1]) {
				res += to_string(i - pre);
				res += temp[pre];
				pre = i;
			}
		}
		res += to_string(i - pre);
		res += temp[pre];
		return res;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	int n;
	while (cin >> n) {
		cout << Solution().countAndSay(n) << endl;
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
