// 12. Integer to Roman.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/**
*最暴力的方法，最大值是3999，把每一位的值都表示出来，一位一位的加上去，不过最后顺序是反的，需要颠倒一下顺序
*厉害的解法：https://leetcode.com/problems/integer-to-roman/discuss/6310/My-java-solution-easy-to-understand
*/
class Solution {
public:
	string intToRoman(int num) {
		vector<vector<string>> list(4);
		list[0] = { "","I","II","III","IV","V","VI","VII","VIII","IX" };//个位
		list[1] = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };//十位
		list[2] = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };//百位
		list[3] = { "","M","MM","MMM" };//千位
		string str;
		vector<string> res;
		res.reserve(20);
		int i = 0;
		while (num) {
			int temp = num % 10;
			num = num / 10;
			res.emplace_back(list[i][temp]);
			i++;
		}
		for (int i = res.size()-1;i>=0;i--)
			str += res[i];
		return str;
	}
};

/**
*用stringstream来做
*/


int main()
{
	freopen("in.txt", "r", stdin);
	int temp;
	Solution s;
	while (cin >> temp) {
		cout << s.intToRoman(temp) << endl;
	}
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
