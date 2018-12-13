// 179. Largest Number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
	string largestNumber(vector<int>& nums) {
		sort(nums.begin(),nums.end(), cmp);//当梳理不出排序规则的时候可以使用泛型算法排序，注意泛型算法是一般默认从小到大排序的。
		string res = "";
		for (int i = 0; i < nums.size(); i++) {
			res += to_string(nums[i]);
		}
		if (res[0] == '0')
			return "0";
		return res;
	}

	static bool cmp(int &str1, int &str2) {
		string num1 = to_string(str1) + to_string(str2);
		string num2 = to_string(str2) + to_string(str1);
		return num1 > num2;
	}

	
};

int main()
{
	freopen("in.txt", "r", stdin);
	vector<int> nums;
	int temp;
	while (cin >> temp)
		nums.push_back(temp);
	Solution s;
	cout << s.largestNumber(nums) << endl;
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
