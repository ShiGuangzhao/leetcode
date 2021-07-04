/*************************************************************************
    > File Name: 344_反转字符串.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月28日 星期一 21时57分00秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            std::swap(s[l++], s[r--]);
        }
    }
};
