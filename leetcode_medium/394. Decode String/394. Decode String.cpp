// 394. Decode String.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/decode-string/submissions/
//解码字符串
//Stack DPS

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

//https://leetcode.com/problems/decode-string/discuss/87543/0ms-simple-C%2B%2B-solution

class Solution {
public:
	string decodeString(string s) {
		int i = 0;
		string res = decodeString(s, i);
		return res;
	}
private:
	string decodeString(string &s, int &i) {
		string res;
		while (i < s.size() && s[i] != ']') {
			if (!isdigit(s[i]))
				res += s[i++];
			else {
				string numStr;
				while (i < s.size() && isdigit(s[i]))
					numStr += s[i++];
				int num = stoi(numStr);
				i++;
				string temp = decodeString(s, i);
				i++;
				while (num-- > 0) {
					res += temp;
				}
			}
		}
		return res;
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




