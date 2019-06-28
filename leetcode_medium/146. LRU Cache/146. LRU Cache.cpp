// 146. LRU Cache.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//https://leetcode.com/problems/lru-cache/
#include "pch.h"
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;


/*
主要就是定义出这个数据结构：unordered_map<int, pair<int, list<int>::iterator>> cache;分别表示key，value，最近使用的key的链表
也可以分成两个map，一个表示key,value 一个表示key,iterator
查找：
直接在map里查找key,O(1)，就找到了对应的value和key所在的链表的迭代器，删除该迭代器，将value插入到表头，更新value对应的迭代器为表头。
插入：
	存在key,将value更新，同时将与value相连的key放到表头，更新map
	不存在key
		满了，删除链表尾巴元素，及map中对应的key，中心插入
		没满，将key插入表头，与value相连
*/

class LRUCache {
public:
	LRUCache(int capacity) {
		sz = capacity;
	}

	//设置或者查询key都算一次操作
	int get(int key) {
		auto it = cache.find(key);
		if (it != cache.end()) {
			update(cache, it);
			return it->second.first;
		}
		return -1;
	}

	void put(int key, int value) {
		auto it = cache.find(key);
		if (it != cache.end()) {
			it->second.first = value;
			update(cache, it);
			return;
		}
		if (cache.size() == sz) {
			int oldKey = used.back();//在链表里存key的原因就在于此，方便map的删除
			cache.erase(oldKey);
			used.pop_back();
			used.push_front(key);
			cache[key] = { value,used.begin() };
		}
		else {
			used.push_front(key);
			cache[key] = { value,used.begin() };
		}
	}
private:
	int sz;
	unordered_map<int, pair<int, list<int>::iterator>> cache;
	list<int> used;//最近使用的key的链表

	void update(unordered_map<int, pair<int, list<int>::iterator>> &cache, unordered_map<int, pair<int, list<int>::iterator>>::iterator it) {
		int key = it->first;
		used.erase(it->second.second);
		used.push_front(key);
		it->second.second = used.begin();

		//cache.erase(it);
		//cache[key] = { val,used.begin() };
	}
};


int main()
{
	LRUCache cache = LRUCache(2 /* capacity */);

	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;       // returns 1
	cache.put(3, 3);    // evicts key 2
	cout << cache.get(2) << endl;       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	cout << cache.get(1) << endl;       // returns -1 (not found)
	cout << cache.get(3) << endl;       // returns 3
	cout << cache.get(4) << endl;       // returns 4
    std::cout << "Hello World!\n"; 
}

