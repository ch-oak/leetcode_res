// 24. Swap Nodes in Pairs.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//交换链表中相邻的两个节点

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {};
};

/**
*解法1：直接交换相邻节点的值，每次步进2
*注意到Node里说不能仅仅交换值，要做到节点的交换，也就是改变连接关系呗
*/

class Solution_1 {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next)
			return head;
		ListNode* cur = head;
		while (cur->next) {
			int tmp = cur->val;
			cur->val = cur->next->val;
			cur->next->val = tmp;
			cur = cur->next;
			if (cur->next)
				cur = cur->next;
			else
				break;
		}
		return head;
	}
};
/**
*交换节点连接方式的方法，需要注意的是要保留交换后的两个节点中的后一个节点pre，在下一次交换
*完成之后，要将pre连上第一个节点
*/
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next)
			return head;
		ListNode* cur = head;
		ListNode* pre = NULL;
		while (cur->next) {
			ListNode* next = cur->next;
			cur->next = next->next;
			next->next = cur;
			if (cur == head)
				head = next;
			if (pre)
				pre->next = next;
			pre = cur;
			if (cur->next)
				cur = cur->next;
			else
				break;
		}
		return head;
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
