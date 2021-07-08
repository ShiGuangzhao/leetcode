/*************************************************************************
    > File Name: 387_字符串中的第一个唯一字符.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年07月08日 星期四 11时13分16秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    const int INIT_VAL = -1;
    const int MORE_THAN_ONE = -2;
public:
    int firstUniqChar(string s) {
        vector<int> mark(26, -1);
        int ret = -1;
        for(auto i = 0; i < s.size(); ++i) {
            auto tmp = s[i] - 'a';
            if(mark[tmp] == INIT_VAL)   mark[tmp] = i;
            else if(mark[tmp] >= 0)     mark[tmp] = MORE_THAN_ONE;
        }
        for(auto index: mark) {
            if(index >= 0) {
                ret = (ret == -1)? index: std::min(ret, index);
            }
        }
        return ret;
    }

    int firstUniqChar1(string s) {
        vector<int> count(26);
        vector<int> order;
        for(auto i = 0; i < s.size(); ++i) {
            if(count[s[i] - 'a']++ == 0) {
                order.push_back(i);
            }
        }
        for(auto i: order) {
            if(count[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
