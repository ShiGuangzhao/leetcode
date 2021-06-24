/*************************************************************************
    > File Name: 283_移动0.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月23日 星期三 13时48分17秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto slow = nums.begin(), fast = nums.begin();
        auto p = nums.begin();
        for(; p != nums.end(); ++p) {
            if(*p == 0) {
                slow = p;
                break;
            }
        }
        if(p == nums.end())  return;
        fast = slow;
        while(++fast != nums.end()) {
            if(*fast != 0) {
                *slow++ = *fast;
            }
        }
        while(slow != nums.end()) {
            *slow++ = 0;
        }

    }
};
