// 102. Binary Tree Level Order Traversalon1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//二叉树的层序遍历，实质是广度优先搜索
//Tree Breadth-first-Search
#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//非递归的层序遍历，队列非递归
class Solution1 {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> next{ {root} };
		vector<vector<int>> res;
		while (!next.empty()) {
			vector<int> level;
			for (int i = 0; i < next.size(); i++) {
				TreeNode* front = next.front();
				next.pop();
				level.push_back(front->val);
				if (front->left) next.push(front->left);
				if (front->right) next.push(front->right);
			}
			res.push_back(level);
		}

		return res;
	}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		levelorder(root, 0, res);
		return res;
	}
	void levelorder(TreeNode* node, int level, vector<vector<int>>& res) {
		if (!node) return;
		if (res.size() == level) res.push_back({});//新加一个vector
		res[level].push_back(node->val);
		if (node->left) levelorder(node->left, level + 1, res);
		if (node->right) levelorder(node->right, level + 1, res);
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
