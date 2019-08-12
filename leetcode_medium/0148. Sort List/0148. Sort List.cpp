// 0148. Sort List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/sort-list/
//链表排序
//Tag：Linked List Sort

#include "pch.h"
#include <iostream>



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
//归并排序
//利用快慢指针将链表断为两截，再将两个链表合并
//一个节点是自然有序的，所以要从先递归到一个节点从一个节点开始合并
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head ->next)
			return head;
		ListNode* fast = head, *slow = head,*pre;
		while (fast&&fast->next) {
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = NULL;
		return merge(sortList(head), sortList(slow));
	}
private:
	ListNode* merge(ListNode* ls1, ListNode* ls2) {
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		while (ls1&&ls2) {
			if (ls1->val < ls2->val) {
				cur->next = ls1;
				cur = cur->next;
				ls1 = ls1->next;
			}
			else {
				cur->next = ls2;
				cur = cur->next;
				ls2 = ls2->next;
			}
			if (ls1) cur->next = ls1;
			if (ls2) cur->next = ls2;
			return dummy->next;
		}
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
