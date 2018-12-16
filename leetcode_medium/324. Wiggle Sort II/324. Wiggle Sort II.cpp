// 324. Wiggle Sort II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		int mid = nums[len / 2];
		vector<int> res(len, mid);
		int low = 1, high = (len % 2) ? len - 1 : len - 2;
		for (int i = len-1; i>0&&nums[i]>mid; i--,low += 2)
			res[low] = nums[i];
		for (int i = 0; i < len&&nums[i] < mid; i++, high -= 2)
			res[high] = nums[i];
		nums = res;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	vector<vector<int>> nums;
	string temp;
	int i = 0;

	//读取多行逗号分格的数据进入vector<vector<int>>
	while (getline(cin, temp)) {//不加分隔符getline读取的是一行数据
		nums.push_back(vector<int>());
		stringstream ss(temp);
		string alpha;
		while(getline(ss,alpha,','))//加了之后读取的是一个分隔符之前的数据
			nums[i].push_back(stoi(alpha));
		i++;
	}
	for (int i = 0; i < nums.size(); i++) {
		Solution s;
		s.wiggleSort(nums[i]);
		for (auto a : nums[i])
			cout << a << " ";
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
