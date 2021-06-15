/*************************************************************************
    > File Name: 242_有效的字母异位词.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月15日 星期二 18时32分32秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram_map(string s, string t) {
        unordered_map<char, int> count;
        for(auto c: s) {
            ++count[c];
        }
        for(auto c: t) {
            --count[c];
        }
        for(auto p: count) {
            if(p.second != 0) {
                return false;
            }
        }
        return true;
    }
    
    bool isAnagram_sort(string s, string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }

    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }

        vector<int> count(26, 0);
        for(auto c: s) {
            ++count[c - 'a'];
        }
        for(auto c: t) {
            --count[c - 'a'];
        }
        for(auto p: count) {
            if(p != 0) {
                return false;
            }
        }
        return true;
    }
};
