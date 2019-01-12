// 29. Divide Two Integers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//不用乘、除、余数操作计算整数除整数

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/**
*首先不是用减法这么简单。结果就是减法这么简单，用位运算不断增加除数，同时记录移动的位数加到结果上
*/

class Solution {
public:
	int divide(int dividend, int divisor) {
		int res = 0;
		int flag = 1;
		if (dividend == INT_MIN&&divisor==-1)
			return INT_MAX;
		if ((dividend< 0 &&divisor > 0)||(dividend >0 && divisor < 0)) 
			flag = -1;
		long long dvd = labs(dividend);
		long long dvs = labs(divisor);
		if (divisor == 1)
			return flag * dvd;
		while (dvd>=dvs) {
			long long mul = 1,temp = dvs;//这里如果用int的话，temp不断增大最后会溢出，计算2147483647/2的话会超时
			while (dvd > (temp << 1)) {
				temp <<= 1;
				mul <<= 1;
			}
			dvd -= temp;
			res += mul;
		}
		return flag*res;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	int dividend, divisor;
	Solution sol;
	while (cin >> dividend >> divisor) {
		cout << sol.divide(dividend, divisor) << endl;
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
