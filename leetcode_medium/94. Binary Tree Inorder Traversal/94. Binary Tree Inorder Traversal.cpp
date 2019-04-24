// 94. Binary Tree Inorder Traversal.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//二叉树的顺序遍历，递归与非递归(先序，中序，后序，层序）（递归，非递归）
//Tags:Hash Table Stack Tree
#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

//二叉树中序遍历，递归方法
class Solution1 {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		dfs(root,res);
		return res;
	}
private:
	void dfs(TreeNode* root, vector<int> &res) {
		if (!root) return;
		if(root->left) dfs(root->left,res);
		res.push_back(root->val);
		if (root->right) dfs(root->right, res);
	}
};
//使用栈进行非递归遍历
class Solution{
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> st;
		TreeNode* temp = root;
		while (temp || !st.empty()) {
			if (temp) {
				st.push(temp);
				temp = temp->left;
			}
			else {
				TreeNode* tp = st.top();
				st.pop();
				res.push_back(tp->val);
				temp = tp->right;
			}
		}
		return res;
	}

};

int main()
{
	TreeNode *root = new TreeNode(0);
	root->val = 1;
	root->left = NULL;
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	auto res = Solution().inorderTraversal(root);
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
