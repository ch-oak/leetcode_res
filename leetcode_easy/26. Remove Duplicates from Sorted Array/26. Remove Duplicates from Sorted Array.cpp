// 26. Remove Duplicates from Sorted Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//返回排好序的数组中重复的数字的数目，并将相异的数字移动到表头

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/**
*用pos记录当前的结果位置，用last记录上一个不相同的值。当与last不同时，pos++,同时替换pos++处的值
*/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int len = nums.size();
		int pos = 0;
		int last = nums[0];
		for (int i = 1; i < len; i++) {
			if (nums[i] != last) {
				nums[++pos] = nums[i];
				last = nums[i];
			}
		}
		return pos+1;
	}
};
int main()
{
	freopen("in.txt", "r", stdin);
	string line;
	Solution s;
	while (getline(cin,line)){
		vector<int> nums;
		string temp;
		stringstream ss(line);
		while (getline(ss, temp, ','))
			nums.push_back(stoi(temp));
		cout << s.removeDuplicates(nums) << endl;
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
