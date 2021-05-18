/*************************************************************************
    > File Name: 49_字母异位分组.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月24日 星期三 15时33分58秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> vecMap;
        for(auto s: strs) {
            string key = s;
            sort(key.begin(), key.end());
            auto it = vecMap.find(key);
            if(it == vecMap.end()) {
                vecMap[key] = vector<string>{s};
            }
            else {
                (*it).second.push_back(s);
            }
        }
        vector<vector<string>> ret;
        for(auto &m: vecMap) {
            ret.push_back(m.second);
        }
        return ret;
    }
};
