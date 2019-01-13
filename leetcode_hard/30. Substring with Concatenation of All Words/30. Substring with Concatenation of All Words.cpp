// 30. Substring with Concatenation of All Words.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/**
应该是动态规划，将每个word出现的pos找出来，能组成几个等差数列
*/

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		int len = words.size();
		vector<vector<int>> all_pos(len);
		for (int i = 0; i < len; i++)
			if (!get_pos(s, words[i], all_pos[i]))
				return {};

	}
private:
	bool get_pos(string s, string word, vector<int> w_pos) {
		string::size_type pos = 0;
		while ((pos = s.find_first_of(word) != string::npos)) {
			w_pos.push_back(pos);
			pos++;
		}
		if (w_pos.empty())
			return false;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	string s;
	while (cin >> s) {
		vector<string> words;
		string line;
		getline(cin, line);
		getline(cin, line); 
		stringstream ss(line);
		string temp;
		while (getline(ss, temp, ',') )
			words.push_back(temp);
		
		cout << s << endl;
		for (auto a : words)
			cout << a << " ";
		cout << endl;
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
