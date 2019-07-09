// 0021. Merge Two Sorted Lists.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//合并两个有序链表
//Easy
//Linked List
//https://leetcode.com/problems/merge-two-sorted-lists/

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {};
};

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

class Solution {
public:
/**
*很简单的思路，新建一个节点，把两条链表中较小的节点接在后面，直到某条链为空，把不空的那条链子接上去
*这里要注意一个问题，不能直接对指针使用！运算符
*/
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(0);
		ListNode* res = head;
		while (l1&&l2) {
			if (l1->val < l2->val) {
				head->next = l1;
				head = head->next;
				l1 = l1->next;
			}
			else {
				head->next = l2;
				head = head->next;
				l2 = l2->next;
			}
		}
		if (l1 != NULL)
			head->next = l1;
		if (l2 != NULL)
			head->next = l2;
		delete res;
		res = nullptr;
		auto temp = res->next;
		return temp;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
