// 141. Linked List Cycle.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>


//Definition for singly-linked list.
 struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 //快慢指针，快指针走两步，慢指针走一步
 //如果相遇说明有环，程序结束
 //如果快指针走到终点，循环结束，说明无环
 //参考：https://leetcode.com/problems/linked-list-cycle/discuss/44489/O(1)-Space-Solution
 class Solution {
 public:
	 bool hasCycle(ListNode *head) {
		 if (!head || !head->next)
			 return true;
		 ListNode *slow = head, *fast = head;
		 while (fast->next&&fast->next->next) {
			 slow = slow->next;
			 fast = fast->next->next;
			 if (slow == fast)
				 return true;
		 }
		 return false;
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
