// 0739. Daily Temperatures.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//下一个温暖的日子还有几天
//Tag:Hash Table Stack
//Medium

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		stack<int> st;
		vector<int> res(T.size(), 0);
		for (int i = 0; i < T.size(); i++) {
			while (!st.empty() && res[i] > T[st.top()]) {//当不递减的时候，计算距离
				int index = st.top();
				st.pop();
				res[index] = i - index;
			}
			st.push(i);//栈里存储递减序列
		}
		return res;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
