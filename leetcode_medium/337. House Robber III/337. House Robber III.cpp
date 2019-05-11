// 337. House Robber III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//不能抢劫相邻的二叉树节点
//Tag:Tree DPS

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int n) :val(n), left(NULL), right(NULL) {};
};

//参考：https://leetcode.com/problems/house-robber-iii/discuss/79330/Step-by-step-tackling-of-the-problem

//二叉树多半用递归的方法做，最直接的想法，先考虑一棵树，再考虑左右子树
class Solution1 {
public:
	int rob(TreeNode* root) {
		if (!root)
			return 0;
		int val = 0;
		if (root->left)
			val += rob(root->left->left) + rob(root->left->right);
		if (root->right)
			val += rob(root->right->left) + rob(root->right->right);
		return max(root->val + val, rob(root->left), rob(root->right));
	}
};

//用unordered_map记录结果
class Solution {
public:
	int rob(TreeNode* root) {
		unordered_map<TreeNode*, int> info;
		return robHelp(root, info);
	}
private:
	int robHelp(TreeNode* root, unordered_map<TreeNode*, int> &info) {
		if (!root)
			return 0;
		if (info.find(root) != info.end())
			return info[root];
		int val = 0;
		if (root->left)
			val += robHelp(root->left->left, info) + robHelp(root->left->right, info);
		if (root->right)
			val += robHelp(root->right->left, info) + robHelp(root->right->right, info);

		int res = max(root->val + val, robHelp(root->left, info) + robHelp(root->right, info));
		info.insert(make_pair(root, res));
		return res;
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
