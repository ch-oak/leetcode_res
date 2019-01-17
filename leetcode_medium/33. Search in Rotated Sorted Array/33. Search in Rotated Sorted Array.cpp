// 33. Search in Rotated Sorted Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//在旋转之后的有序序列中找指定值，要求复杂度为O(logn)

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;


/**
*想到是二分查找，但是查找pivot的过程不就O(n)了吗
*/
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 0) return -1;
		if (len == 1) return target == nums[0] ? 0 : -1;
		int pivot = find_pivot(nums, 0, len - 1);
		if (target == nums[pivot]) return pivot;
		if (pivot == 0) return binary_search(nums, 0, len - 1, target);
		if (target == nums[0]) return 0;
		if (target > nums[0]) return binary_search(nums, 0, pivot-1, target);
		return binary_search(nums, pivot, len - 1, target);
	}
private:
	int find_pivot(vector<int>& nums, int left, int right) {
		int len = nums.size();
		if (nums[left] < nums[right])
			return 0;
		while (left <= right) {
			int pivot = (left + right) / 2;
			if (pivot<len-1 && nums[pivot] > nums[pivot + 1])
				return pivot + 1;
			else {
				if (nums[pivot] > nums[left])
					left = pivot + 1;
				else
					right = pivot - 1;
			}
		}
		return 0;
	}

	int binary_search(vector<int>& nums, int left, int right,int target) {
		while (left <= right) {
			int pivot = (left + right) / 2;
			if (nums[pivot] == target)
				return pivot;
			else {
				if (nums[pivot] > target)
					right = pivot - 1;
				else
					left = pivot + 1;
			}
		}

		return -1;
	}
};
int main()
{
	freopen("in.txt", "r", stdin);
	string line;
	Solution sol;
	while (getline(cin,line)) {
		string temp;
		stringstream ss(line);
		vector<int> vec;
		while (getline(ss, temp, ','))
			vec.push_back(stoi(temp));
		int target;
		cin >> target;
		getline(cin, line);
		cout << sol.search(vec, target) << endl;
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
