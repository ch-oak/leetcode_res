// 234. Palindrome Linked List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/palindrome-linked-list/
//判断链表是否为回文链表
//Tag:Linked List Two Pointers

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int n) :val(n), next(NULL) {}
};

//快慢指针加栈：https://www.cnblogs.com/grandyang/p/4635425.html
//将数据放入vector中，根据下标做比较
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head)
			return true;
		vector<int> nums;
		while (head) {
			nums.push_back(head->val);
			head = head->next;
		}
		int len = nums.size();
		for (int i = 0; i <= len >> 2 - 1; i++) {
			if (nums[i] != nums[len - 1 - i])
				return false;
		}
		return true;
	}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		ListNode* t
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
