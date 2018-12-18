// 57. Insert Interval.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include <stdio.h>
#include <windef.h>

using namespace std;



struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

/**
*思路1：先将newInterval按照start从小到大的顺序插入intervals,
*起先的思路是将newInterval插入在一个比他小的Interval前面，但是没考虑newInterval比其他Interval都大的情况
*解决重叠的过程需要将重合的Interval合并，考虑两种情况pre完全包含next，pre部分包含next
*但是速度过慢仅超越%1.18用户，使用了过多的erase,push_back,insert
*/
//class Solution {
//public:
//	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
//		if (intervals.empty()) {
//			intervals.push_back(newInterval);
//			return intervals;
//		}
//		int start = newInterval.start;
//		int end = newInterval.end;
//		int len = intervals.size();
//		for (auto it = intervals.begin(); it != intervals.end(); it++) {
//			if (start <= (*it).start) {
//				intervals.insert(it, newInterval);
//				break;
//			}
//				
//		}
//		if (intervals.size() == len)
//			intervals.push_back(newInterval);
//
//		auto pre = intervals.begin();
//		for (auto it = ++intervals.begin(); it != intervals.end(); it++) {
//			if ((*pre).end >= (*it).start&&(*pre).end<=(*it).end) {//pre包含了部分it
//				(*pre).end = (*it).end;
//				intervals.erase(it);
//				it = pre;
//			}
//			else if ((*pre).end >= (*it).start && (*pre).end > (*it).end) {//pre完全包含it
//				intervals.erase(it);
//				it = pre;
//			}
//			else {
//				pre++;
//			}
//		}
//		return intervals;
//	}
//};

/**
*思路2：按照https://www.cnblogs.com/ganganloveu/p/4158450.html思路重新实现了一次
*一边遍历intervals一边更新newInterval,如果newInterval与intervals[i]无重叠：①newInterval在intervals[i]之前,直接压入newInterval和后续intervals[i]，返回结果
*②如果newInterval在intervals[i]之后，压入intervals[i]，继续遍历
*如果有重叠，更新newInterval的star和end,继续遍历
*最后压入newInterval(如果程序没结束）
*时间还是只到31%，应该还是push_back的原因
*/
class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {

		if (intervals.empty()) {
			intervals.push_back(newInterval);
			return intervals;
		}

		vector<Interval> ret;
		ret.reserve(intervals.size() + 1);
		int len = intervals.size();
		for (int i = 0; i < len; i++) {
			//无重复
			//在下一个之前
			if (newInterval.end < intervals[i].start) {
				ret.push_back(newInterval);
				for (; i < len; i++)
					ret.push_back(intervals[i]);
				return ret;
			}
			//在下一个之后
			else if (newInterval.start > intervals[i].end) {
				ret.push_back(intervals[i]);
			}
			//有重叠
			else {
				newInterval.start = min(newInterval.start, intervals[i].start);
				newInterval.end = max(newInterval.end, intervals[i].end);
			}

		}
		ret.push_back(newInterval);
		return ret;
	}

};

int main()
{
	vector<Interval> intervals = { Interval(1,3),Interval(6,9) };
	Interval newInterval(2, 5);
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
