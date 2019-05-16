// 406. Queue Reconstruction by Height.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/queue-reconstruction-by-height/
//重建队列
//Tag:Greedy
//元素1表示高度，元素2表示前面队列不比元素1高的元素的数目
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//参考：https://www.cnblogs.com/grandyang/p/5928417.html
//先按高度和数目排列，载逐个插入
class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b)
		{return a[0] > b[0] || (a[0] == b[0]&&a[1] < b[1]); });
		vector<vector<int>> res;
		for (auto a : people) {
			res.insert(res.begin() + a[1], a);
		}
		return res;
	}
};

int main()
{
	vector<vector<int>> people{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
	auto res = Solution().reconstructQueue(people);
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
