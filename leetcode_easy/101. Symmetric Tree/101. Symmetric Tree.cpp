// 101. Symmetric Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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
 
  //递归，参考：https://www.cnblogs.com/jimmycheng/p/7104233.html
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		return isSymmetric(root->left, root->right);
	}
private:
	bool isSymmetric(TreeNode* left, TreeNode* right) {
		if (left == NULL && right == NULL)
			return true;
		if (left == NULL || right == NULL)
			return false;
		if (left->val != right->val)
			return false;
		return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->left->left = new TreeNode(4);
	root->right->left = new TreeNode(3);
	cout << Solution().isSymmetric(root);
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
