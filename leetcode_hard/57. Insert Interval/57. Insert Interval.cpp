// 57. Insert Interval.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

/**
*思路：先将newInterval按照start从小到大的顺序插入intervals,
*起先的思路是将newInterval插入在一个比他小的Interval前面，但是没考虑newInterval比其他Interval都大的情况
*解决重叠的过程需要将重合的Interval合并，考虑两种情况pre完全包含next，pre部分包含next
*但是速度过慢超越1.18用户
*/

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		if (intervals.empty()) {
			intervals.push_back(newInterval);
			return intervals;
		}
		int start = newInterval.start;
		int end = newInterval.end;
		int len = intervals.size();
		for (auto it = intervals.begin(); it != intervals.end(); it++) {
			if (start <= (*it).start) {
				intervals.insert(it, newInterval);
				break;
			}
				
		}
		if (intervals.size() == len)
			intervals.push_back(newInterval);

		auto pre = intervals.begin();
		for (auto it = ++intervals.begin(); it != intervals.end(); it++) {
			if ((*pre).end >= (*it).start&&(*pre).end<=(*it).end) {//pre包含了部分it
				(*pre).end = (*it).end;
				intervals.erase(it);
				it = pre;
			}
			else if ((*pre).end >= (*it).start && (*pre).end > (*it).end) {//pre完全包含it
				intervals.erase(it);
				it = pre;
			}
			else {
				pre++;
			}
		}
		return intervals;
	}
};

int main()
{
	vector<Interval> intervals = { Interval(1,5)};
	Interval newInterval(2, 7);
	Solution s;
	vector<Interval> res = s.insert(intervals, newInterval);
	for (auto e : res) {
		cout << "[" << e.start << "," << e.end << "]";
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
