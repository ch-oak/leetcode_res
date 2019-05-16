// 437. Path Sum III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/path-sum-iii/
//和为指定值的路径数目

#include "pch.h"
#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};


//参考：https://leetcode.com/problems/path-sum-iii/discuss/91889/Simple-Java-DFS
class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		if (!root) return 0;
		return pathSumFrom(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);//从根节点开始，和根节点左下开始，右下开始，双重递归
	}
public:
	int pathSumFrom(TreeNode* root, int num) {
		if (!root) return 0;
		return (root->val == num ? 1 : 0) + pathSumFrom(root->left, num - root->val) + pathSumFrom(root->right, num - root->val);
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
