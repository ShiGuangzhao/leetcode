/*************************************************************************
    > File Name: 28_实现strStr.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月22日 星期一 13时53分21秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};
