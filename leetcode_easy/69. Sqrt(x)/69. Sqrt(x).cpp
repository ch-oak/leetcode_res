// 69. Sqrt(x).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//对一个数开平方

#include "pch.h"
#include <iostream>

/**
*用二分查找，查找第一个平方大于x的数，将结果-1
*/
class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1)
			return x;
		int left = 1, right = x;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (x / mid >= mid) left = left + 1;
			else right = mid;
		}
		return right - 1;
	}
};
/**
*牛顿迭代法：https://www.cnblogs.com/huashanqingzhu/p/6635691.html
*/
class Solution {
public:
	int mySqrt(int x) {
		if (x == 0) return 0;
		double res = 1, pre = 0;
		while (abs(res - pre) > 1e-6) {
			pre = res;
			res = (res + x / res) / 2;//新的res是比原来更加接近结果的一个根，总会逼近最佳结果
		}
		return int(res);
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
