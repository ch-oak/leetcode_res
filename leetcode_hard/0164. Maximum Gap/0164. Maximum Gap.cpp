// 0164. Maximum Gap.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//最大间隔
//Sort
//Hard
//无序数组的排序后的最大间隔，线性时间内解决
//https://leetcode.com/problems/maximum-gap/

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
class max_min {
public:
	max_min() {
		max = INT_MIN;
		min = INT_MAX;
	}
	int max;
	int min;
	bool empty() {
		if (max == INT_MIN && min == INT_MAX)
			return true;
		else
			return false;
	}
};
int main()
{


	//freopen("in.txt", "r", stdin);
	//int temp;
	//vector<int> nums;
	//while (cin >> temp)
	//	nums.push_back(temp);
	//int n = nums.size();
	//if (n < 2)
	//	return 0;
	//if (n == 2)
	//	return abs(nums[0] - nums[1]);
	//int min_ele = *min_element(nums.begin(), nums.end());
	//int max_ele = *max_element(nums.begin(), nums.end());
	//int bucket_size = ceil((max_ele - min_ele) / (n - 1));
	//if (bucket_size == 0)
	//	return 0;
	//vector<set<int>> buckets(n+1);
	//for (int i = 0; i < n; i++) {
	//	int num = floor((nums[i] - min_ele) / bucket_size);
	//	buckets[num].insert(nums[i]);
	//}
	//int res = INT_MIN;
	//auto pre = buckets[0];
	//for (int i = 1; i < n-1;i++) {
	//	if (!buckets[i].empty()) {
	//		int temp = *buckets[i].begin() - *(--pre.end());
	//		if (res < temp)
	//			res = temp;
	//		pre = buckets[i];
	//	}
	//}
	//cout << res;

	freopen("in.txt", "r", stdin);
	int temp;
	vector<int> nums;
	while (cin >> temp)
		nums.push_back(temp);
	int n = nums.size();
	if (n < 2)
		return 0;
	if (n == 2)
		return abs(nums[0] - nums[1]);
	double min_ele = *min_element(nums.begin(), nums.end());
	double max_ele = *max_element(nums.begin(), nums.end());
	int bucket_size = ceil((max_ele - min_ele) / (n - 1));
	if (bucket_size == 0)
		return 0;
	int bucket_num = ceil((max_ele - min_ele) / bucket_size);
	vector<max_min> buckets(bucket_num + 1);
	for (int i = 0; i < n; i++) {
		int num = floor((nums[i] - min_ele) / bucket_size);
		if (nums[i] > buckets[num].max)
			buckets[num].max = nums[i];
		if (nums[i] < buckets[num].min)
			buckets[num].min = nums[i];
	}
	int res = INT_MIN;
	auto pre = buckets[0];
	for (int i = 1; i < bucket_num + 1; i++) {
		if (!buckets[i].empty()) {
			int temp = buckets[i].min - pre.max;
			if (res < temp)
				res = temp;
			pre = buckets[i];
		}
	}
	cout << res;
}
