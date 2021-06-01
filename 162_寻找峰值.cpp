/*************************************************************************
    > File Name: 162_寻找峰值.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月28日 星期五 16时57分34秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1 or nums[0] > nums[1]) {
            return 0;
        }
        auto i = 2;
        while(i < nums.size() and nums[i] > nums[i - 1]) {
            ++i;
        }
        return i - 1;
    }
};
