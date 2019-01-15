// 30. Substring with Concatenation of All Words.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定字符串s,和一串words，找出所有包含所有words的位置

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

/**
*应该是动态规划，将words中每个word出现的pos找出来，能组成几个等差数列
*可能会出现重复的单词，所以不正确，不对，好像也可以
*使用dfs超时了
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

class Solution1 {
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
			pos++;
		}
		if (w_pos.empty())
			return false;
		return true;
	}

	void dfs(set<int> &res, set<int> seq, vector<vector<int>> &all_pos, int i) {//想要seq递归调用的时候增加，递归回来的时候又复原，应该不能用引用
		if (i > len)
			return;
		if(!seq.empty()&&(*seq.rbegin()-*seq.begin()>word_len*(len-1)))
			return;
		if (seq.size() == len) {
			auto front = seq.begin();
			auto cur = ++seq.begin();
			while (cur != seq.end()) {
				if (*cur - *front != word_len)
					break;
				++front;
				++cur;
			}
			if(cur==seq.end())
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


/**
*参考：https://leetcode.com/problems/substring-with-concatenation-of-all-words/discuss/13658/Easy-Two-Map-Solution-(C%2B%2BJava)
*双map法，一个map用于存储所有word出现的次数，一个map用于记录从s的i位置走num个word长度word出现的次数，当出现差异时自增i
*/
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		if (s.empty() || words.empty())
			return {};
		unordered_map<string, int> count;
		for (auto word : words)
			count[word]++;
		int n = s.size(), len = words[0].size(), num = words.size();
		vector<int> res;
		for (int i = 0; i < n - num * len + 1; i++) {
			unordered_map<string, int> seen;
			int j = 0;
			for (; j < num ; j++) {
				string temp = s.substr(i+j*len, len);
				if (count.find(temp) != count.end()) {
					seen[temp]++;
					if (seen[temp] > count[temp])
						break;
				}
				else
					break;
			}
			if (j == num)
				res.push_back(i);
		}
		return res;
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

