// 338. Counting Bits.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

//参考：https://www.cnblogs.com/liujinhong/p/6115831.html
//最简单的方法和利用先前计算的结果
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res(num + 1, 0);
		for (int i = 0; i <= num; i++) {
			res[i] = numOne(i);
		}
		return res;
	}
private:
	int numOne(int num) {
		int res = 0;
		while (num) {
			res += num & 1;
			num >>= 1;
		}
		return res;
	}
};
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res(num + 1, 0);
		for (int i = 1; i <= num; i++) {
			res[i] = res[i >> 1] + (i & 1);
		}
		return res;
	}
};


int main()
{
	Solution().countBits(5);
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
