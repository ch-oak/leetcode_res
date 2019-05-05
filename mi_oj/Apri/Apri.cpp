// Apri.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

int fact[1000005];

using namespace std;

int isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)
			return 0;
	}
	return 1;
}
int factorNum(int N) {
	int numOfDivisors;

	if (1 == N)
	{
		numOfDivisors = 1;  // 1 has only one divisor
	}
	else
	{
		numOfDivisors = 2;  // 1 and itself are its divisor

		for (int i = 2; i <= (int)sqrt((double)N); i++)
		{
			if (N%i == 0)
			{
				if (i*i == N)
				{
					numOfDivisors++;  // i = N/i only divisor
				}
				else
				{
					numOfDivisors += 2; // i and N/i are its divisors
				}
			}
		}
	}
	return numOfDivisors;
}
bool cmp(int num1, int num2) {
	int fac1 = fact[num1];//factorNum(num1);
	int fac2 = fact[num2];// factorNum(num2);
	if (fac1 == fac2)
		return num1 < num2;
	else
		return fac1 < fac2;
}



int main()
{
	//freopen("in.txt", "r", stdin);

	int a, b;
	while (cin >> a >> b) {
		cout << a + b << endl;
	}
	return 0;
	
	for (int i = 1; i < 100002;i++) {
		fact[i] = factorNum(i);
	}
	int k, n;
	cin >> k >> n;
	vector<int> nums(n);
	while (n--) {
		int temp;
		cin >> temp;
		nums[nums.size() - n - 1] = temp;
	}
	sort(nums.begin(), nums.end(), cmp);
	cout << nums[k - 1];
	return 0;
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
