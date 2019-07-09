// 0088. Merge Sorted Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//合并两个有序数组
//Easy
//Array Two Pointers

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;


/*
Note:
The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/
class Solution {
public:
	//双指针，一个指向nums1末尾,一个指向nums2末尾，从尾巴往前填充
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1, k = m + n - 1;
		while (i >= 0 && j >= 0) {
			if (nums1[i] > nums2[j]) {
				nums1[k--] = nums1[i--];
			}
			else {
				nums1[k--] = nums2[j--];
			}
		}
		if (j >= 0) {
			while (j >= 0)
				nums1[k--] = nums2[j--];
		}
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
