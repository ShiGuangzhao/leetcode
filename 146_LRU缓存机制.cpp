/*************************************************************************
    > File Name: 146_LRU缓存机制.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月20日 星期四 18时20分59秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

class LRUCache {
private:
    list<pair<int, int>> keyList;
    unordered_map<int, list<pair<int, int>>::iterator> lruMap;
    int size;

public:
    LRUCache(int capacity)
        :size(capacity) {
    }

    int get(int key) {
        auto node = lruMap.find(key);
        if(node == lruMap.end())    return -1;
        keyList.splice(keyList.begin(), keyList, node->second);
        return node->second->second;
    }

    void put(int key, int value) {
        auto node = lruMap.find(key);
        if(node != lruMap.end()) {
            node->second->second = value;
            keyList.splice(keyList.begin(), keyList, node->second);
        }
        else {
            keyList.push_front({key, value});
            lruMap[key] = keyList.begin();
            if(lruMap.size() > size) {
                lruMap.erase(keyList.back().first);
                keyList.pop_back();
            }
        }
    }
};
