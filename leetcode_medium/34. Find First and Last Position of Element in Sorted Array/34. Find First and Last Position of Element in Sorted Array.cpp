// 34. Find First and Last Position of Element in Sorted Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//在一个排好序的数组（可能有重复数字）里找到指定数字的起始和结束位置

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/**
*解法1：用二分查找找到指定目标，再分别向前向后遍历，感觉应该复杂度超过O(logn)了
*/
class Solution1 {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty())
			return { -1,-1 };
		int len = nums.size();
		int pos = binarySearch(nums, 0, len - 1, target);
		if (pos == -1)
			return { -1,-1 };
		int left = pos, right = pos;
		while (left - 1 >= 0 && nums[left - 1] == target)
			left--;
		while (right + 1 <= len - 1 && nums[right + 1] == target)
			right++;
		return { left,right };
	}
private:
	int binarySearch(vector<int>& nums, int left, int right,int target) {
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] > target)
				right = right - 1;
			else
				left = mid + 1;
		}
		return -1;
	}
};

/**
*解法2：用两次二分法查找与target相等或者比target大的下标，第一次确定左范围，第二次确定右范围
*/
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty())
			return { -1,-1 };
		int len = nums.size();
		int left = binarySearch(nums, target);
		if (left == len||nums[left]!=target)
			return { -1,-1 };
		int right = binarySearch(nums, target + 1);
		return { left,right-1};
	}
private:
	int binarySearch(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size();
		while (left < right) {//不能把令right = len-1,条件换成小于等于，当nums[right]==target时，会陷入死循环
			int mid = (right + left) / 2;
			if (nums[mid] < target)
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	string line;
	while (getline(cin,line)) {
		stringstream ss(line);
		string temp;
		vector<int> nums;
		while (getline(ss, temp, ','))
			nums.push_back(stoi(temp));
		getline(cin, temp);
		int target = stoi(temp);
		vector<int> res = Solution().searchRange(nums, target);
		for (auto a : res)
			cout << a << " ";
		cout << endl;
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
