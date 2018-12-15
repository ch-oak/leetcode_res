// 164. Maximum Gap.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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
<<<<<<< HEAD
    std::cout << "Hello Git!    \n"; 
=======
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
	vector<max_min> buckets(bucket_num+1);
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

>>>>>>> fd2b6eb82629b9c0e16028dfb7376b26994a31fd
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
