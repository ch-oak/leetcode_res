// 35. Search Insert Position.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//查找数组中指定值的位置或者插入位置
//Tags:Array Binary Search

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


/**
*直接用二分查找，找到了返回下标，没找到返回二分查找中的left
*/
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty())
			return 0;
		return binarySearch(nums, target);
	}
private:
	int binarySearch(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] > target)
				right = mid - 1;
			else
				left = mid + 1;
		}
		return left;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	string line;
	while (getline(cin,line)) {
		vector<int> nums;
		stringstream ss(line);
		string temp;
		while (getline(ss, temp, ','))
			nums.push_back(stoi(temp));
		int target;
		getline(cin, temp);
		target = stoi(temp);
		cout << Solution().searchInsert(nums, target) << endl;
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
