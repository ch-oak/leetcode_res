// 105. Construct Binary Tree from Preorder and Inorder Traversal.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//根据二叉树前序遍历和中序遍历的结果，构建二叉树
//Array Tree Depth-first Search
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//递归：https://www.cnblogs.com/springfor/p/3884034.html
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
private:
	TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
		if (preStart > preEnd || inStart > inEnd)//到尽头了，只用一个条件应该也可以
			return NULL;
		int rootVal = preorder[preStart];
		int rootIndex = find(inorder.begin(),inorder.end(),rootVal) - inorder.begin();
		int lenLeft = rootIndex - inStart;
		TreeNode* root = new TreeNode(rootVal);
		root->left = buildTree(preorder, preStart + 1, preStart + lenLeft, inorder, inStart, rootIndex - 1);
		root->right = buildTree(preorder, preStart + lenLeft + 1,preEnd, inorder, rootIndex + 1, inEnd);
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
