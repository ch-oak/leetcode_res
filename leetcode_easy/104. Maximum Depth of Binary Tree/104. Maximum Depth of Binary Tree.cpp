// 104. Maximum Depth of Binary Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//参考102题二叉树的层序遍历，每增加一层，就递增结果
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		int level = 1;
		queue<TreeNode*> cur{ {root} };
		while (!cur.empty()) {
			for (int i = cur.size(); i > 0; i--) {
				TreeNode* tp = cur.front();
				cur.pop();
				if (tp->left) cur.push(tp->left);
				if (tp->right) cur.push(tp->right);
			}
			if (!cur.empty())
				level++;
		}
		return level;
	}
};


//简单的深度优先搜索：https://www.cnblogs.com/bakari/p/4126693.html
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		int l = maxDepth(root->left);
		int r = maxDepth(root->right);
		return l > r ? l + 1 : r + 1;
	}
};


int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	cout << Solution().maxDepth(root);
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
