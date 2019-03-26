// 3. Longest Substring Without Repeating Characters.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
/**
双指针窗口移动：https://blog.csdn.net/qq_37174526/article/details/81283888
*/
class Solution1 {
public:
	int lengthOfLongestSubstring(string s) {
		int len = s.size();
		if (len <= 1)
			return len;
		int left = 0, right = 0;
		int maxlen = 1;
		set<char> substr;
		while (left < len&&right < len) {
			if (substr.find(s[right]) == substr.end()) {
				//当s[right]与前面所有字符都不重复的时候，更新最长不重复子字符串
				substr.insert(s[right]);
				right++;
				maxlen = max(right - left, maxlen);
			}
			else {
				//当s[right]与前面某个字符重复的时候，不断右移left
				substr.erase(s[left]);
				left++;
			}
		}
		return maxlen;
	}
};

/**
双指针法的改进，用map记录上所有字符的位置。
*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int len = s.size();
		if (len <= 1)
			return len;
		int left = 0, right = 0;
		int maxlen = 1;
		map<char,int> note;
		while (left < len&&right < len) {
			if (note.find(s[right]) != note.end()) {
				//当substr[right]与前面的字符重复的时候，不是一步一步的递增left，而是直接通过map来实现跳越
				//值得注意的是不能直接找与上一个s[right]字符上一次出现的位置加1，而是得取当前left与上一次出现位置加1中的大值
				//否则会把left拉到前面去，会计算重复字符串的长度，比如"abba"，a的上一个出现位置加1到a之间包含了重复的字符
				//left = substr[s[right]] + 1;//错误
				left = max(left, note[s[right]] + 1);
			}
			note[s[right]] = right;
			maxlen = max(maxlen, right - left + 1);
			right++;
		}
		return maxlen;
	}
};

int main()
{
	cout << Solution().lengthOfLongestSubstring("abba");
    //std::cout << "Hello World!\n"; 
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
