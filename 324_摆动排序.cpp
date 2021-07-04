/*************************************************************************
    > File Name: 324_摆动排序.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月28日 星期一 13时58分27秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        auto ret = nums;
        int i = 0;
        // 1 2 3 4 5 6  -> 3
        // 3 6 2 5 1 4
        // 1 2 3 4 5    -> 2
        // 2 5 1 4 3
        if(nums.size() % 2 != 0) {
            int j = (nums.size() - 1) / 2;
            ret[0] = nums[j];
            while(++i < j) {
                ret[2*i] = nums[j - i + 1];
                ret[2*i - 1] = nums[nums.size() - i + 1];
            }
        }
        else {
            int j = nums.size() / 2;
            while(i < j) {
                ret[2*i] = nums[j - i - 1];
                ret[2*i + 1] = nums[nums.size() - i - 1];
                ++i;
            }
        }
        nums = ret;
    }
};
