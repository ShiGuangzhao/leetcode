/*************************************************************************
    > File Name: 171_EXCEL列表序号.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月30日 星期日 14时12分00秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int titleToNumber2(string columnTitle) {
        int64_t ret = 0;
        int64_t power = 1;
        for(auto it = columnTitle.rbegin(); it != columnTitle.rend(); ++it) {
            ret += (*it - 'A' + 1) * power;
            power *= 26;
        }
        return int(ret);
    }

    int titleToNumber(string columnTitle) {
        int ret = 0;
        for(auto c: columnTitle) {
            ret = 26 * ret + (c - 'A' + 1);
        }
        return ret;
    }
};
