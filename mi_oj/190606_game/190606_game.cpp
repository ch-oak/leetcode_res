// 190606_game.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	//int t;
	//cin >>t;
	//while (t--) {
	//	int n, k;
	//	cin >> n >> k;
	//	double res = k * 0.5;
	//	long long  i_res = 100 * res;
	//	res = i_res / 100.0;
	//	
	//	if (t != 0) {
	//		printf("%.2f\n", res);
	//	}
	//	else {
	//		printf("%.2f", res);
	//	}

	//}
	cout << 16 % 1000000007;
	int n;
	cin >> n;
	int n_ = n;
	vector<pair<int, int>> points;
	while (n--) {
		int x, y;
		cin >> x >> y;
		points.push_back({ x,y });
	}

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
