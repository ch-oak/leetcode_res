// 19. Remove Nth Node From End of List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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
 
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int len = 0;
		ListNode* cur = head;
		ListNode* pre = head;
		int len = 0;
		while (cur->next) {
			if (len > 0)
				pre = pre->next;
			len++;
			cur = cur->next;
		}
		int pos = len - n;
		return head;
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
