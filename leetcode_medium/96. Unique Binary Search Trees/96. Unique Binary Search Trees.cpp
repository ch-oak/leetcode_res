// 96. Unique Binary Search Trees.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//n个节点可以组成多少种结构不同的二叉树

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

/**
*动态规划
*/
class Solution {
public:
	int numTrees(int n) {
		if (n <= 0)
			return 0;
		vector<int> res(n + 1, 0);
		res[0] = 1;
		res[1] = 1;
		for (int i = 2; i <= n; i++) {//i为总的节点数
			for (int j = 0; j < i; j++) {
				res[i] += res[j] * res[i - 1 - j];//j为右子树节点数，i-1-j为左子树节点数
			}
		}
		return res[n];
	}
};

int main()
{
	cout << Solution().numTrees(3);
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
