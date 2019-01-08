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
*应该是前面的reverse 2-group的升级版
*/
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		int num = 0;
		ListNode* cur = head;
		while (cur) {
			cur = cur->next;
			num++;
		}
		int time = num / k;
		cur = head;
		ListNode* pre = NULL;
		ListNode* next = NULL;

		vector<ListNode*> note(time + 1);
		note[0] = head;
		for (int i = 0; i < time; i++) {
			int len = 1;
			while (cur->next) {  
				next = cur->next;
				cur->next = pre;
				pre = cur;
				cur = next;
				if (++len >= k)
					break;
			}
			if (i > 0 && i < time - 1)
				note[i - 1]->next = cur;
			else if(i==time-1)
				note[i]->next = next;
			if (i == 0)
				head = cur;

			cur->next = pre;
			cur = next;	
		}
		return head;
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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
