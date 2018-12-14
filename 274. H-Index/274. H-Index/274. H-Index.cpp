// 274. H-Index.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

//class Solution {
//public:
//	int hIndex(vector<int>& citations) {
//		int res = 0;
//		while (!citations.empty()) {
//			int num = 0;
//			auto it = citations.begin();
//			while (it != citations.end()) {
//				if (*it >= res) {
//					num++;
//					it++;
//				}
//				else {
//					it = citations.erase(it);
//				}
//					
//			}
//			if (num < res) {
//				res--;
//				break;
//			}
//			res++;
//
//		}
//		return res;
//	}
//};

//class Solution {
//public:
//	int hIndex(vector<int>& citations) {
//		int res = 0;
//		while (!citations.empty()) {
//			vector<int> temp;
//			int num = 0;
//			auto it = citations.begin();
//			while (it != citations.end()) {
//				if (*it >= res) {
//					num++;
//					temp.push_back(*it);
//				}
//				it++;
//			}
//			if (num < res) {
//				res--;
//				break;
//			}
//			citations = temp;
//			//citations.assign(temp.begin(), temp.end());
//			res++;
//
//		}
//		return res;
//	}
//};

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int res = 0;
		sort(citations.begin(), citations.end());
		int len = citations.size();
		for (int i = 0; i < len; i++) {
			if (citations[i] >= len - i)
				res = citations[i];
			if (res > len - i)
				break;
		}

		return res;
	}
};

int main()
{

	freopen("in.txt", "r", stdin);
	vector<int> citations;
	string str;
	while (getline(cin, str,','))
		citations.push_back(stoi(str));
	Solution s;
	cout << s.hIndex(citations);
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
