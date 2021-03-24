/*************************************************************************
    > File Name: 27_移除元素.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月23日 星期二 19时28分27秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int last = nums.size() - 1;
        int i = 0;
        while(i <= last) {
            if(nums[i] == val) {
                while(nums[last] == val) {
                    if(last == i) {
                        return --last;
                    }
                    // nums.pop_back();
                    --last;
                }
                nums[i] = nums[last--];
                // nums.pop_back();
            }
            ++i;
        }
        return last + 1;
    }
};
