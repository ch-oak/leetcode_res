// 61. Rotate List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>


//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
/**
*将链表转换为循环链表，找到新的尾指针
*/
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head)
			return NULL;
		if (!head->next||k==0)
			return head;
		ListNode* tail = head;
		int len = 1;
		while (tail->next) {
			tail = tail->next;
			len++;
		}
		tail->next = head;
		int rem = k % len;
		int move = len - rem;
		ListNode* new_tail = head;
		for (int i = 1; i < move; i++)
			new_tail = new_tail->next;
		ListNode* new_head = new_tail->next;
		new_tail->next = NULL;
		return new_head;
	}
};

int main()
{
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
