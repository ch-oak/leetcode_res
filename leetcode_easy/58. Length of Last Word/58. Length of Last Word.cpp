// 58. Length of Last Word.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//返回字符串中最后一个单词的长度，单词用空格隔开，空格数目不定
//Tag:string
#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/**
*解法1：从尾巴上逐一遍历，注意next应该初始化为-1。
*/
class Solution {
public:
	int lengthOfLastWord(string s) {
		int pre, next = -1;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] != ' ') {
				pre = i;
				break;
			}
		}
		if (pre == -1)
			return 0;
		for (int j = pre; j >= 0; j--) {
			if (s[j] == ' ') {
				next = j;
				break;
			}
		}
		return pre - next;
	}
};
/**
*解法2：更简洁的写法
*/
class Solution {
public:
	int lengthOfLastWord(string s) {
		int length = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] != ' ')
				length++;
			else {
				if (length == 0)
					continue;
				else
					break;
			}
		}
		return length;
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
