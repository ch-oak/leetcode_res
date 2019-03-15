// 56. Merge Intervals.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

 //Definition for an interval.
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

 bool cmp(const Interval& inter1, const Interval& inter2) {
	 return inter1.start < inter2.start;
 }
 
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.empty())
			return {};
		vector<Interval> res;
		res.push_back(intervals[0]);
		for (int i = 0; i < intervals.size(); i++) {
			if (res.back().end < intervals[i].start)
				res.push_back(intervals[i]);
			else
				res.back().end = max(res.back().end, intervals[i].end);
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
