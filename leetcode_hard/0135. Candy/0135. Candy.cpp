// 0135. Candy.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//分糖果
//Greedy
//Hard
//根据分数分糖果，每个同学至少分到一个糖果，并且如果分数比相邻同学高，糖果也要比相邻同学多
//https://leetcode.com/problems/candy/

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//从左往右遍历会保证向右的递增序列满足条件，对于这些递增序列来说至少得有这么多个糖果
//从右往左遍历会保证向左的递增序列满足条件，同样对于这些递增序列来说至少得有这么多个糖果
//两个序列的较小值即为最终结果

class Solution {
public:
	int candy(vector<int>& ratings) {
		int n = ratings.size(), sum = 0;
		vector<int> left(n, 1), right(n, 1);
		//从左往右扫描
		for (int i = 1; i < n; i++) {
			if (ratings[i] > ratings[i - 1])
				left[i] = left[i - 1] + 1;
		}
		//从右往左扫描
		for (int i = n - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1])
				right[i] = right[i + 1] + 1;
			sum += max(left[i], right[i]);//
		}
		sum += max(right[n - 1], left[n - 1]);
		return sum;
	}
};

//public int candy(int[] ratings) {
//	int candies[] = new int[ratings.length];
//	Arrays.fill(candies, 1);// Give each child 1 candy 
//
//	for (int i = 1; i < candies.length; i++) {// Scan from left to right, to make sure right higher rated child gets 1 more candy than left lower rated child
//		if (ratings[i] > ratings[i - 1]) candies[i] = (candies[i - 1] + 1);
//	}
//
//	for (int i = candies.length - 2; i >= 0; i--) {// Scan from right to left, to make sure left higher rated child gets 1 more candy than right lower rated child
//		if (ratings[i] > ratings[i + 1]) candies[i] = Math.max(candies[i], (candies[i + 1] + 1));
//	}
//
//	int sum = 0;
//	for (int candy : candies)
//		sum += candy;
//	return sum;
//}


int main()
{
	std::cout << "Hello World!\n";
}
