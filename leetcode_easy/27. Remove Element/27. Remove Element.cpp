// 27. Remove Element.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//移动一个数组中指定的数，并将其他数字置于前面

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int pos = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != val) {
				nums[pos] = nums[i];
				pos++;
			}
		}
		return pos;
	}
};
int main()
{
	freopen("in.txt", "r", stdin);
	string line;
	Solution sol;
	
	while (getline(cin, line)) {
		vector<int> nums;
		int val;
		stringstream ss(line);
		string temp;
		while (getline(ss, temp, ',')) {
			nums.push_back(stoi(temp));
		}
		cin >> val;
		getline(cin, line);//用了cin，所以这里的getline要再吃一行字符串
		cout << sol.removeElement(nums,val);
	}

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
