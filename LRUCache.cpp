/*
 * LRUCache.cpp
 *
 *  Created on: 2014/3/21
 *      Author: comeonelton
 */

#include "LRUCache.h"

#include <iostream>

using namespace std;

LRUCache::LRUCache(int capacity)
	: head(NULL), tail(NULL), capacity(capacity), length(0)
{
}

LRUCache::~LRUCache() {
	CacheEntry *p = head;
	while (p) {
		CacheEntry *tmp = p;
		p = p->next;
		delete tmp;
	}
}

void LRUCache::printCache()
{
	CacheEntry *p = head;
	while (p) {
		cout << "(" << p->key << ", " << p->value << ")";
		p = p->next;
	}
	cout << endl;
}

void LRUCache::mov2head(CacheEntry* p)
{
	if (p == head)
		return;

	if (p == tail) {
		if (tail != head)
			tail = p->prev;
	}

	if (p->next)
		p->next->prev = p->prev;

	if (p->prev)
		p->prev->next = p->next;

	add2head(p);
}

void LRUCache::add2head(CacheEntry* p)
{
	if (head) {
		head->prev = p;
	} else {
		// Empty
		tail = p;
	}
	p->next = head;
	head = p;
}

void LRUCache::removeTail()
{
	tail->prev->next = NULL;
	tail = tail->prev;
}

int LRUCache::get(int key)
{
	cout << "get(" << key << ") = ";
	int ret = -1;
	CacheEntry* p = head;
	while (p) {
		if (p->key == key) {
			ret = p->value;
			mov2head(p);
			break;
		}
		p = p->next;
	}
	cout << ret << endl;
	printCache();
	return ret;
}

void LRUCache::set(int key, int value)
{
	cout << "set(" << key << ", " << value << ")" << endl;
	CacheEntry* p = head;
	bool found = false;
	while (p) {
		if (p->key == key) {
			p->value = value;
			mov2head(p);
			found = true;
			break;
		}
		p = p->next;
	}

	if (!found) {
		CacheEntry* newEntry = new CacheEntry(key, value);
		add2head(newEntry);
		length++;
		if (length > capacity) {
			removeTail();
		}
	}
	printCache();
}

// TODO: generate massive and random input
void LRUCache::execute()
{
	LRUCache c(5);
	c.set(5, 10);
	c.set(1, 2);
	c.set(13, 26);
	c.get(13);
	c.get(1);
	c.set(7, 14);
	c.set(3, 6);
	c.get(7);
	c.set(23, 46);
	c.get(5);
	c.get(3);
	c.get(1);
	c.set(7, 21);
}
