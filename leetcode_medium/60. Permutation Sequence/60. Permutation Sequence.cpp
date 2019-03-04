// 60. Permutation Sequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//返回第k个完全排列
//Math BackTracking

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> factor(n + 1, 1);
		for (int i = 1; i <= n; i++)
			factor[i] = i * factor[i - 1];
		int n_copy = n-1;
		string digits = "123456789";
		string res = "";
		while (n_copy) {
			int th = (k-1) / factor[n_copy--];//规律
			k = k - th * factor[n_copy+1];
			res += digits[th];
			digits.erase(digits.begin() + th);
		}
		res += digits[k-1];
		return res;
	}
};


int main()
{
	cout << Solution().getPermutation(4, 14);
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
