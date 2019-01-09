// 25. Reverse Nodes in k-Group.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一个链表和数字k，k个k个的反转

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};



/**
*应该是前面的reverse 2-group的升级版,真滴是难受，因为在循环里重定义了cur,出了循环cur又被全局cur覆盖，一直没找出原因
*主要还是链表反转，和dummy node的设置
*/
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k == 1 || !head)
			return head;
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* left = dummy;
		ListNode* cur = head;
		ListNode*  right;
	
		int i = 0;
		while (cur) {
			ListNode *tmp = cur;
			for (i = 1; i < k && cur; i++) 
					cur = cur->next;
			
			if (i == k&&cur!=NULL) {
				right = cur->next;
				ListNode* pre = left->next;
				cur = pre->next;
				while (cur != right) {
					pre->next = cur->next;
					cur->next = left->next;
					left->next = cur;
					cur = pre->next;
				}

				left = pre;
		


			}
			else
				break;
			
		}
		return dummy->next;
	}
};

int main()
{
	ListNode* head = new ListNode(-1);
	ListNode* cur = head;
	int a[5] = { 5,4,3,2,1 };
	for (int i = 0; i < 5; i++) {
		ListNode* tmp = new ListNode(a[i]);
		tmp->next = head->next;
		head->next = tmp;
	}
	Solution s;
	ListNode* res = s.reverseKGroup(head->next, 3);
	while (res) {
		cout << res->val << ",";
		res = res->next;
	}
    std::cout << "Hello World!\n"; 
}


