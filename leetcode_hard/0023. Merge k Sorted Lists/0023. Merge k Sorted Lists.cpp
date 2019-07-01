// 0023. Merge k Sorted Lists.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//k归并
//Linked List	Divide and Conquer	Heap
//Hard
//合并n个有序链表
//https://leetcode.com/problems/merge-k-sorted-lists/

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {};
};

/**
*方法1：使用Merge Two Sorted Lists的方法，一个一个的加入lists中的元素
*不过时间非常慢，仅比18%的提交快
*/
class Solution1 {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
			return NULL;
		ListNode* res = lists[0];
		for (int i = 1; i < lists.size(); i++) {
			res = mergeTwoLists(res, lists[i]);
		}
		return res;
	}
private:
	ListNode* mergeTwoLists(ListNode *left, ListNode* right) {
		ListNode* head = new ListNode(-1);
		ListNode* cur = head;
		while (left&&right) {
			if (left->val < right->val) {
				cur->next = left;
				left = left->next;
			}
			else {
				cur->next = right;
				right = right->next;
			}
			cur = cur->next;
		}
		if (left)
			cur->next = left;
		if (right)
			cur->next = right;
		ListNode* res = head->next;
		ListNode* del = head;
		delete del;
		return res;
	}
};
/**
*参考：https://www.cnblogs.com/skysand/p/4300711.html
*方法2：两项两项的合并，快了很多，比60%快
*/
class Solution2 {
public:
	ListNode* mergeKLists(vector<ListNode*> lists) {
		if (lists.empty())
			return 0;
		int k = lists.size();
		while (k > 0) {
			bool odd = k % 2;//剩余长度为奇数还是偶数
			k = odd ? (k + 1) / 2 : k / 2;
			for (int i = 0; i < (odd ? k - 1 : k); i++)
				lists[i] = mergeTwoLists(lists[i], lists[i + k]);
			if (k == 1)
				break;
		}
		return lists[0];
	}
private:
	ListNode* mergeTwoLists(ListNode *left, ListNode* right) {
		ListNode* head = new ListNode(-1);
		ListNode* cur = head;
		while (left&&right) {
			if (left->val < right->val) {
				cur->next = left;
				left = left->next;
			}
			else {
				cur->next = right;
				right = right->next;
			}
			cur = cur->next;
		}
		if (left)
			cur->next = left;
		if (right)
			cur->next = right;
		ListNode* res = head->next;
		ListNode* del = head;
		delete del;
		return res;
	}
};

/**
*参考：https://www.cnblogs.com/grandyang/p/4606710.html
*方法3：使用最小堆，将一层节点放入优先队列中，这里说一下，默认的优先队列相当于大顶堆，所以要重新定义比较函数
*/
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*> lists) {
		auto cmp = [](ListNode* l1, ListNode*l2) {return l1->val > l2->val; };
		priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
		for (int i = 0; i < lists.size(); i++) {
			if (lists[i])
				q.push(lists[i]);
		}
		ListNode *head = NULL, *pre = NULL, *tmp = NULL;
		while (!q.empty()) {
			tmp = q.top();
			q.pop();
			if (!pre) head = tmp;
			else pre->next = tmp;
			pre = tmp;
			if (tmp->next) q.push(tmp->next);
		}
		return head;
	}
};
int main()
{
	int* p = NULL;
	if (!p)
		cout << "test" << endl;
	std::cout << "Hello World!\n";
}
