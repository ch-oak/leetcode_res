// 114. Flatten Binary Tree to Linked List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
	void flatten(TreeNode* root) {//是值传递，所以不能用重新构造一棵树，替代这个地址的方法
		if (!root)
			return;
		stack<TreeNode*> st;
		TreeNode* temp = root;
		vector<TreeNode*> res;
		while (!st.empty() || temp) {
			if (temp) {
				st.push(temp);
				res.push_back(temp);
				temp = temp->left;
			}
			else {
				TreeNode* top = st.top();
				st.pop();
				temp = top->right;
			}
		}
		TreeNode* root_res = root;
		root->val = res[0]->val;
		TreeNode* right = NULL;
		for (int i = 1; i < res.size(); i++) {
			if (i == 1) {
				root_res->right = new TreeNode(res[i]->val);
				right = root_res->right;
			}
			else {
				right->right = new TreeNode(res[i]->val);
				right = right->right;
			}
		
		}
		root = root_res;
	}
};

class Solution {
public:
	void flatten(TreeNode* root) {//是值传递，所以不能用重新构造一棵树，替代这个地址的方法
		if (!root)
			return;
		stack<TreeNode*> st;
		TreeNode* temp = root;
		set<int> res;
		while (!st.empty() || temp) {
			if (temp) {
				st.push(temp);
				temp = temp->left;
			}
			else {
				TreeNode* top = st.top();
				st.pop();
				res.insert(top->val);
				temp = top->right;
			}
		}
		TreeNode* root_res = root;
		root->val = *res.begin();
		root->left = NULL;
		TreeNode* right = NULL;
		auto temp_it = res.begin();
		temp_it++;
		for (auto it = temp_it; it != res.end(); it++) {
			if (it == temp_it) {
				root_res->right = new TreeNode(*it);
				right = root_res->right;
			}
			else {
				right->right = new TreeNode(*it);
				right = right->right;
			}

		}
	}
};

int main()
{

	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = NULL;
	root->right->right = new TreeNode(6);
	Solution1().flatten(root);
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
