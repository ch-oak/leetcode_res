// 49. Group Anagrams.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//Tag:
#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		auto strs_copy = strs;
		set<string> unique;
		for (int i = 0; i < strs.size(); i++) {
			sort(strs[i].begin(), strs[i].end());
			unique.insert(strs[i]);
		}
		vector<string> unique_vec(unique.begin(),unique.end());
		vector<vector<string>> res(unique.size());
		for (int i = 0; i < strs.size(); i++) {
			auto pos = find(unique_vec.begin(),unique_vec.end(),strs[i]);
			auto num = pos - unique_vec.begin();
			res[num].push_back(strs_copy[i]);
		}
		return res;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	string line;
	while (getline(cin,line)) {
		vector<string> strs;
		stringstream ss(line);
		string temp;
		while (getline(ss, temp, ','))
			strs.push_back(string(temp, 1, temp.size() - 2));
		auto res = Solution().groupAnagrams(strs);
		for (auto vec : res) {
			for (auto v : vec)
				cout << v << " ";
			cout << endl;
		}
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
