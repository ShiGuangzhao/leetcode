/*************************************************************************
    > File Name: 395_至少有K个重复字符的最长子串.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年07月09日 星期五 12时59分15秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    using Count_t = unordered_map<char, int>;

    bool isSubstring(string s, int k) {
        Count_t count;
        for(auto c: s) {
            ++count[c];
        }
        for(auto p: count) {
            if(p.second < k)    return false;
        }
        return true;
    }

public:
    // 暴力解法
    // 超出时间限制
    int longestSubstring1(string s, int k) {
        int ret = 0;
        for(auto i = 0; i < s.size(); ++i) {
            for(int j = s.size() - i; j > ret; --j) {
                if(j >= k and isSubstring(s.substr(i, j), k)) {
                    ret = j;
                }
            }
        }
        return ret;
    }

    // 动态规划
    int longestSubstring(string s, int k) {
        if(k == 1)  return s.size();
        int ret = 0;
        auto sSize = s.size();

        for(auto i = 0; i + ret < sSize; ++i) {
            Count_t tmp{{s[i], 1}};
            bool flag = false;
            for(auto j = i + 1; j < sSize; ++j) {
                ++tmp[s[j]];
                if(flag) {
                    if(tmp[s[j]] < k) {
                        flag = false;
                    }
                }
                else {
                    flag = true;
                    for(auto p: tmp) {
                        if(p.second < k) {
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag)    ret = max(ret, j - i + 1);
            }
        }
        return ret;
    }
};
