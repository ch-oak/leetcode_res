// 208. Implement Trie (Prefix Tree).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//字典树，根节点为空，每个节点表示一个词或者某个词的前缀
//Tag:Design Trie

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

//参考：https://blog.csdn.net/aishangyutian12/article/details/51932825
//每个节点下有容量为26的节点指针数组，表示下一个节点
class TrieNode {
public:
	TrieNode *child[26];
	bool isWord;//到当前为止是否是一个词，即是到这里结束还是前缀
	TrieNode() :isWord(false) {
		for (auto &a : child) a = NULL;
	}
};
class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* tmp = root;
		for (auto c : word) {
			int i = c - 'a';
			if (!tmp->child[i]) tmp->child[i] = new TrieNode();
			tmp = tmp->child[i];
		}
		tmp->isWord = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* tmp = root;
		for (auto c : word) {
			int i = c - 'a';
			if (!tmp->child[i]) return false;
			tmp = tmp->child[i];
		}
		return tmp->isWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode* tmp = root;
		for (auto c : prefix) {
			int i = c - 'a';
			if (!tmp->child[i]) return false;
			tmp = tmp->child[i];
		}
		return true;
	}
private:
	TrieNode *root;
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
