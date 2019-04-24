// 98. Validate Binary Search Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//判断一棵树是否为二叉排序树
//Tag:Tree Depth-first Search

#include "pch.h"
#include <iostream>
#include <vector>

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
	bool isValidBST(TreeNode* root) {
		vector<int> res;
		dfs(root, 0, res);
		if (res.size() == 1|| res.size() == 0)
			return true;
		for (int i = 0; i < res.size()-1; i++) {
			if (res[i] >= res[i + 1])
				return false;
		}
		return true;
	}
private:
	bool dfs(TreeNode* root,int pre,vector<int> &res) {
		if (!root)
			return true;
		if (root->left) dfs(root->left,pre,res);
		res.push_back(root->val);
		if (root->right) dfs(root->right, pre,res);
		return true;
	}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		TreeNode* pre = NULL;
		return dfs(root, pre);
		
	}
private:
	bool dfs(TreeNode* root, TreeNode* &pre) {
		if (root==NULL) return true;
		if (!dfs(root->left,pre)) return false;
		if(pre!=NULL&&pre->val >= root->val) 
			return false;
		pre = root;
		return dfs(root->right, pre);
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(1);
	//root->left = new TreeNode(1);
	//root->right = new TreeNode(4);
	//root->right->left = new TreeNode(3);
	//root->right->right = new TreeNode(6);

	//TreeNode* root = new TreeNode(2);
	//root->left = new TreeNode(1);
	//root->right = new TreeNode(3);
	std::cout << Solution().isValidBST(root);
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
