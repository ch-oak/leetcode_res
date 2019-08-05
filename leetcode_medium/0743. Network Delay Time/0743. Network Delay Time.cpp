// 0743. Network Delay Time.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/network-delay-time/
//网络延迟时间
//Heap DFS BFS Graph


//可以用最短路算法来做，从某一点发送信号到所有点的最短时间，即从起点到所有点的距离的最短路径的最大值
//Dijkstra算法和BellMan Ford算法求出了起点到其他点的距离
//Floyd算法求出了任意两点之间的最短距离
//感觉Bellman Ford算法和Floyd算法有点像，都是不断更新i到j的最短距离。

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Bellman Ford算法，复杂度O(N*E)
class Solution1 {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		vector<int> dis(N + 1, INT_MAX);//因为下标是从1开始的所以需要等于N+1
		dis[K] = 0;
		for (int i = 1; i <= N; i++) {//下标从1开始
			for (auto e : times) {
				int u = e[0], v = e[1], w = e[2];
				if (dis[u] != INT_MAX && dis[u] + w < dis[v]) dis[v] = dis[u] + w;
			}
		}

		bool flag = 1;
		for (auto e : times) {
			int u = e[0], v = e[1], w = e[2];
			if (dis[u] != INT_MAX && dis[u] + w < dis[v]) {//如果N-1次松驰结束后，还可以松驰说明存在负权回路
				flag = 0;
				break;
			}
		}


		int res = 0;

		//求出最短路径中最长的那一条
		for (int i = 1; i <= N; i++)//下标从1开始
			res = max(res, dis[i]);
		if (res == INT_MAX)
			return -1;
		else
			return res;
	}
};


//Floyd算法，可以求任意两点之间的最短距离，最终的dis[i][j]为i到j的最短距离，复杂度O(N*N)
class Solution2 {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		vector<vector<int>> dis(N + 1, vector<int>(N+1));//因为下标是从1开始的所以需要等于N+1

		//初始化矩阵，自己到自己为0，自己到其他为为无穷
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j)
					dis[i][j] = 0;
				else
					dis[i][j] = INT_MAX;
			}
		}

		//加入边权
		for (auto e : times) {
			int u = e[0], v = e[1], w = e[2];
			dis[u][v] = w;//有向图所以只需要，赋值一次
		}

		//不断更新i到j的距离,只经过1点，经过1,2点，经过1,2,3点，经过1,2,3，...N点
		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (dis[i][k] != INT_MAX && dis[k][j] != INT_MAX)//如果不做这个判断可能会越界
					if (dis[i][j] > dis[i][k] + dis[k][j])
						dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}

		int res = 0;
		//求出最短路径中最长的那一条
		for (int i = 1; i <= N; i++)//下标从1开始
			res = max(res, dis[K][i]);
		if (res == INT_MAX)
			return -1;
		else
			return res;
	}
};

//Dijkstra算法
class Solution3 {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		vector<int> dis(N + 1, INT_MAX);//因为下标是从1开始的所以需要等于N+1
		dis[K] = 0;
		for (int i = 1; i <= N; i++) {//下标从1开始
			for (auto e : times) {
				int u = e[0], v = e[1], w = e[2];
				if (dis[u] != INT_MAX && dis[u] + w < dis[v]) dis[v] = dis[u] + w;
			}
		}
		int res = 0;

		//求出最短路径中最长的那一条
		for (int i = 1; i <= N; i++)//下标从1开始
			res = max(res, dis[i]);
		if (res == INT_MAX)
			return -1;
		else
			return res;
	}
};





int main()
{

	vector<vector<int>> times{ {2,1,1},{2,3,1},{3,4,1} };
	int N = 4, k = 2;
	Solution().networkDelayTime(times, N, k);
    std::cout << "Hello World!\n"; 
}

