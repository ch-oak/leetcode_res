// 4628_删完回文序列的最少次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string str;
int len, dp[65537], cycle[65537], tot;//cycle是处理出来的回文子序列，tot记录个数
bool cle(int x)//判断x状态是否为回文
{
	if (x == 0)
	{
		return true;
	}
	int i = 0, j = len - 1;
	while (i < j)
	{
		while ((x&(1 << i)) == 0)//找到子状态最左边的1
			i++;

		while ((x&(1 << j)) == 0)//找到子状态最右边的1
			j--;
		if (str[i] != str[j])
			return false;
		i++;
		j--;
	}
	return true;
}
int main()
{
	freopen("in.txt", "r", stdin);
	int N;
	cin >> N;
	while (N--)
	{
		tot = 0;
		memset(dp, 0x3F, sizeof(dp));//将dp中的每个数字置为00111111
		//dp[0]=0;
		cin >> str;
		len = str.length();
		int maxx = (1 << len) - 1;//总的状态数目
		for (int i = 1; i <= maxx; i++)
		{
			if (cle(i))//判断状态i是否为回文，状态i是指，00001111，0表示删除对应位置的字符，1表示保留对应位置的字符
			{
				dp[i] = 1;//dp[i]表示状态是i时最少删除的次数，状态i是回文序列时候只需要删除一次
				cycle[++tot] = i;
			}
		}
		//cout<<tot<<endl;
		for (int i = 1; i <= maxx; i++)
		{
			for (int j = 1; j <= tot; j++)
			{
				if ((i&cycle[j]) == 0)
				{
					dp[i | cycle[j]] = min(dp[i | cycle[j]], dp[i] + 1);//要判断在i的位上是否已有1存在
				}
			}
		}

		cout << dp[maxx] << endl;
	}

    std::cout << "Hello World!\n"; 
}
