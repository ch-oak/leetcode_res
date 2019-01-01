// 19. Remove Nth Node From End of List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//返回一个链表中倒数第n个元素

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>



struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
/**
*本题中的链表头结点也存储了元素，一个简单的思路是倒数第n（n>=1&&n<=len)个节点就是正数第len+1-n个节点（1到len)，
*删除该节点即用下一个节点将它覆盖，cur->val = cur->next->val;cur->next = cur->next->next;
*有两种特殊的情况①len==1直接返回空指针②删除最后一个元素cur = NULL;
*/
class Solution1 {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {


		ListNode* cur = head;
		ListNode* pre = head;
		ListNode* last = head;
		int len = 1;
		while (cur->next) {
			if (len > 1)
				pre = pre->next;
			len++;
			cur = cur->next;
		}
		int pos = len - n;
		if (n == 1) {
			if (len == 1)
				return head->next;
			pre->next = NULL;
			return head;
		}
		else
			while (pos--)
				last = last->next;
		last->val = last->next->val;
		last->next = last->next->next;
		return head;
	}
};

/**
*另外一种思路，设置两个指针，一个指针先跑n步，另一个指针再开始跑，找到要删除的节点前一个节点（防止删除节点为最后一个
*节点时无法用下一个节点覆盖要删除的节点），另外还需要考虑只有一个节点的情况，要删除的节点为头节点的情况。
*/
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head->next == NULL)//只有一个节点
			return NULL;
		ListNode* res = head;
		ListNode* pre_des = head;
		int n_copy = n;
		int len = 1;
		while (head->next) {
			len++;
			head = head->next;
			if (--n_copy < 0)
				pre_des = pre_des->next;
		}
		if (n == 1)//删除尾节点
			pre_des->next = NULL;
		else if (n == len)//删除头节点
			return res->next;
		else {
			ListNode* des = pre_des->next;
			des->val = des->next->val;
			des->next = des->next->next;
		}
		return res;
	}
};
void insert_node(ListNode* head, int val) {
	ListNode* new_node = new ListNode(val);
	new_node->next = head->next;
	head->next = new_node;
}
using namespace std;
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {

	}
};
int main()
{
	freopen("in.txt", "r", stdin);
	string line;
	ListNode* head = new ListNode(0);
	
	while (getline(cin, line)) {
		string temp;
		stringstream ss(line);
		while (getline(ss, temp, ','))
			insert_node(head, stoi(temp));
		
	}

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
