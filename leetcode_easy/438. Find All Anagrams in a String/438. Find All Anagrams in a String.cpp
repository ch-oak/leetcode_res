// 438. Find All Anagrams in a String.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//找出所有异序次出现位置
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


//最直接的想法，找出p的所有全排列，再到s中去找，内存溢出
class Solution1 {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<string> words;
		permulate(words, p, 0);
		vector<int> res;
		for (int i = 0; i < words.size(); i++) {
			int beg = -1;
			while ((beg=s.find(words[i],beg+1))!=string::npos) {
				res.push_back(beg);
			}
		}
		return res;
	}
private:
	void permulate(vector<string> &res, string &p, int k) {
		if (k == p.size() - 1) {
			res.push_back(p);
			return;
		}
		for (int i = k; i < p.size(); i++) {
			if (!check(p, k, i - 1, i)) continue;
			swap(p[k], p[i]);
			permulate(res, p, k + 1);
			swap(p[k], p[i]);
		}
	}
	bool check(string& p, int start, int end, int target) {
		for (int i = start; i <= end; i++) {
			if (p[i] == p[target])
				return false;
		}
		return true;
	}
};

//从s开头遍历，每次截取一个子串比较，模板用hash表记录
class Solution2 {
public:
	vector<int> findAnagrams(string s, string p) {
		int len = p.size();
		if (s == "" || s.size() < len)
			return {};
		vector<int> cnt(256, 0);
		for (auto a : p) cnt[a]++;
		vector<int> res;
		for (int i = 0; i <= s.size() - len; i++) {
			bool success = true;
			vector<int> tmp = cnt;
			for (int j = i; j < i + len; j++) {
				if (--tmp[s[j]] < 0) {
					success = false;
					break;
				}
			}
			if (success)
				res.push_back(i);
		}
		return res;
	}
};


class Solution3 {
public:
	vector<int> findAnagrams(string s, string p) {
		int len = p.size();
		if (len > s.size())
			return {};
		vector<int> res;
		map<char, int> note;
		for (int i = 0; i < len; i++)
			++note[p[i]];
		int beg = 0, end = 0;
		int count = note.size();
		while (end < s.size()) {
			if (note.find(s[end]) != note.end()) {
				note[s[end]]--;
				if (note[s[end]] == 0)
					count--;
			}
			end++;
			while (count == 0) {

			}
		}
	}
};


//参考：https://www.cnblogs.com/grandyang/p/6014408.html
//滑动窗口法
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		if (s.empty()) return {};
		vector<int> res, m(256, 0);
		int left = 0, right = 0, cnt = p.size(), n = s.size();
		for (char c : p) ++m[c];
		while (right < n) {
			if (m[s[right++]]-- >= 1) --cnt;//如果在右边界hash表中则记录减1
			if (cnt == 0) res.push_back(left);
			if (right - left == p.size() && m[s[left++]]++ >= 0) ++cnt;//前面做了自检，所以变成大于等于0，如果左边界在hash表中则记录加1
		}
		return res;
	}
};

int main()
{
	string s = "cbaebabacd",p = "abc";
	auto res = Solution().findAnagrams(s, p);
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
