// 50. Pow(x, n).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//求指数
//Tag:Math Binary Search

#include "pch.h"
#include <iostream>
#include <string>
#include "limits.h"

using namespace std;

/**
*解法1：n次方分解为2的指数形式
*/
class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1;
		if (n == INT_MIN)//n可能为-2^31次方，直接取绝对值会越界
			return myPow(x*x, n / 2);
		if (n < 0) {
			x = 1 / x;
			n = -n;
		}
		double pow = 1;
		while (n) {
			if (n % 2 == 1)//相当与n&1
				pow *= x;
			x *= x;
			n >>= 1;	
		}
		return pow;
	}
};

int main()
{
	cout << Solution().myPow(2, 10) << endl;
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
