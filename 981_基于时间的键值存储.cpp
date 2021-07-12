/*************************************************************************
    > File Name: 981_基于时间的键值存储.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年07月10日 星期六 13时44分01秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class TimeMap {
private:
    unordered_map<string, map<int, string>> rec;

public:
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        rec[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if(rec.find(key) == rec.end()) {
            return "";
        }
        for(auto it = rec[key].rbegin(); it != rec[key].rend(); ++it) {
            if(it->first <= timestamp) {
                return it->second;
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
