// 215. Kth Largest Element in an Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//返回无序数组中第k大的元素
//Divide and Conquer Heap

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;


//直接排序
class Solution1 {
public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), std::greater<int>());
		return nums[k - 1];
	}
};


//优先队列
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int len = nums.size();
		priority_queue<int, vector<int>, greater<int> > pq;
		for (int i = 0; i < k; i++) {
			pq.push(nums[i]);
		}
		for (int i = k; i < len; i++) {
			if (nums[i] >= pq.top()) {
				pq.pop();
				pq.push(nums[i]);
			}
		}
		return pq.top();
	}
};
int main()
{
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
