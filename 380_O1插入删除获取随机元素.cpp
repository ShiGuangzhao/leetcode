/*************************************************************************
    > File Name: 380_O1插入删除获取随机元素.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年07月08日 星期四 13时41分34秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> valSet;
    vector<decltype(valSet.begin())> addr;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(valSet.find(val) != valSet.end()) {
            return false;
        }
        valSet[val] = addr.size();
        addr.push_back(valSet.find(val));
        // cout << "size in: " << addr.size() << endl;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto tmp = valSet.find(val);
        if(tmp != valSet.end()) {
            auto index = tmp->second;
            addr[index] = addr.back();
            addr[index]->second = index;
            addr.pop_back();
            valSet.erase(tmp);
            // cout << "size rm: " << addr.size() << endl;
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        // cout << "size get: " << addr.size() << endl;
        auto i = rand() % addr.size();
        return addr[i]->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
