// 30. Substring with Concatenation of All Words.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

/**
*应该是动态规划，将words中每个word出现的pos找出来，能组成几个等差数列
*可能会出现重复的单词，所以不正确，不对，好像也可以
*/

/**
Input
"aaaaaaaa"
["aa","aa","aa"]
Output
[0,2]
Expected
[0,1,2]
*/

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		if (s.empty() || words.empty())
			return {};
		len = words.size();
		word_len = words[0].size();
		vector<vector<int>> all_pos(len);
		for (int i = 0; i < len; i++) {
			if (!get_pos(s, words[i], all_pos[i]))
				return {};
		}

		if (all_pos.size() < len)
			return {};
		set<int> res;
		set<int> seq;
		dfs(res, seq, all_pos, 0);

		return vector<int>(res.begin(),res.end());

	}
private:

	int len;
	int word_len;
	bool get_pos(string &s, string &word, vector<int> &w_pos) {
		string::size_type pos = 0;
		while ((pos = s.find(word,pos)) != string::npos) {
			w_pos.push_back(pos);
			pos += word_len;
		}
		if (w_pos.empty())
			return false;
		return true;
	}

	void dfs(set<int> &res, set<int> seq, vector<vector<int>> &all_pos, int i) {//想要seq递归调用的时候增加，递归回来的时候又复原，应该不能用引用
		if (seq.size() > len)
			return;
		if(!seq.empty()&&(*seq.rbegin()-*seq.begin()>word_len*(len-1)))
			return;
		if (seq.size() == len) {
			res.insert(*seq.begin());
			return;
		}
		for (int k = 0; k < all_pos[i].size(); k++) {
			set<int> temp(seq.begin(), seq.end());
			if (temp.find(all_pos[i][k]) == temp.end()) {
				temp.insert(all_pos[i][k]);
				dfs(res, temp, all_pos, i + 1);
			}
			else
				continue;
		}
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	string s;
	Solution sol;
	while (cin >> s) {
		vector<string> words;
		string line;
		getline(cin, line);
		getline(cin, line); 
		stringstream ss(line);
		string temp;
		while (getline(ss, temp, ',') )
			words.push_back(temp);
		
		auto res = sol.findSubstring(s, words);
		for (auto a : res)
			cout << a << " ";
		cout << endl;
	}
}

