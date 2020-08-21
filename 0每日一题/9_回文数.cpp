/*************************************************************************
    > File Name: 9_回文数.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年08月19日 星期三 17时07分13秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // if(x < 0) {
            // return false;
        // }
        string s(to_string(x));
        cout << s << endl;
        for(auto beg = s.begin(), end = --(s.end()); beg < end; --end, ++beg){
            if(*beg != *end) {
                return false;
            }
        }
        return true;
    }
};
