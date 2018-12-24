// 11. Container With Most Water.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
/**
*思路1
*最简单的暴力求解法，找出任意两个围栏间的面积，求出最大值，时间复杂度为O(n2)
*/
class Solution_1 {
public:
	int maxArea(vector<int>& height) {
		int res = 0;
		int len = height.size();
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				int h = min(height[i], height[j]);
				int temp = h * (j - i);
				if (temp > res)
					res = temp;
			}
		}
		return res;
	}
};

/**
*思路2，参考：https://blog.csdn.net/qq_34228570/article/details/79534467
*设置两个指针一个开头，一个结尾，从两边往回遍历，哪边小哪边往回移动，找到最大容量
*这个应该是半贪心的算法，每次移动，水都可能会增加，并且一定会经过理想情况
*这个同学：https://segmentfault.com/a/1190000008824222 用反证法证明了。假设p_left到perfect_left了，
*p_right还没到perfect_rigth,他要继续移动只有p_right大于p_left,与题设矛盾了，此时容水量大于perfect状况
*/
class Solution {
public:
	int maxArea(vector<int>& height) {
		int beg = 0;
		int end = height.size()-1;
		int max = 0;
		while (beg != end) {
			if (height[beg] < height[end]) {
				int temp = (end - beg)*(height[beg]);
				max = temp > max ? temp : max;
				beg++;
			}
			else {
				int temp = (end - beg)*height[end];
				max = temp > max ? temp : max;
				end--;
			}
		}

		return max;
	}
};


int main()
{
	freopen("in.txt", "r", stdin);
	string str;
	Solution s;
	while (getline(cin, str)) {
		stringstream str_in(str);
		string temp;
		vector<int> lines;
		while (getline(str_in, temp, ',')) {
			lines.push_back(stoi(temp));
		}
		cout << s.maxArea(lines);
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
