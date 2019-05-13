// 347. Top K Frequent Elements.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/top-k-frequent-elements/
//出现次数最多的k个元素

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second > p2.second;
}

//map记录出现的次数，再放到vector里进行排序，注意泛型算法只能对有序容器进行排序
class Solution1 {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> note;
		for (int i = 0; i < nums.size(); i++) {
			note[nums[i]]++;
		}
		vector<pair<int, int>> res(note.begin(), note.end());
		sort(res.begin(), res.end(), cmp);
		vector<int> ret(k);
		for (int i = 0; i < k; i++) {
			ret[i] = res[i].first;
		}
		return ret;
	}
private:

};


//桶排序，桶的下标表示出现的次数
//https://leetcode.com/problems/top-k-frequent-elements/discuss/81623/Simple-C%2B%2B-solution-using-hash-table-and-bucket-sort
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {//key并不有序
		unordered_map<int, int> m;
		for (int num : nums)
			++m[num];

		vector<vector<int>> buckets(nums.size() + 1);//可能有频率相同的数字
		for (auto p : m)
			buckets[p.second].push_back(p.first);

		vector<int> ans;
		for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i) {
			for (int num : buckets[i]) {
				ans.push_back(num);
				if (ans.size() == k)
					break;
			}
		}
		return ans;
	}
};
int main()
{
	vector<int> nums{ 1,1,1,2,2,3 };
	Solution().topKFrequent(nums, 2);
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
