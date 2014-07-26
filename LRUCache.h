/*
 * LRUCache.h
 *
 *  Created on: 2014/3/21
 *      Author: comeonelton
 */

#ifndef LRUCACHE_H_
#define LRUCACHE_H_

#include <iostream>

struct CacheEntry {
	int key;
	int value;
	CacheEntry* prev;
	CacheEntry* next;
	CacheEntry(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
};

class LRUCache {
public:
	LRUCache(int capacity);
    virtual ~LRUCache();

    void printCache();
    int get(int key);
    void set(int key, int value);

    static void execute();

private:
    void mov2head(CacheEntry* p);
    void add2head(CacheEntry* p);
    void removeTail();
    CacheEntry *head;
    CacheEntry *tail;
    int capacity;
    int length;
};

#endif /* LRUCACHE_H_ */
