/*************************************************************************
    > File Name: 384_打乱数组.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年07月09日 星期五 12时12分42秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> initNums;

public:
    Solution(vector<int>& nums) {
        initNums = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return initNums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shufNums(initNums.size(), INT32_MAX);
        int count = shufNums.size() - 1;
        while(count >= 0) {
            auto index = rand() % shufNums.size();
            if(shufNums[index] == INT32_MAX) {
                shufNums[index] = initNums[count--];
            }
        }
        return shufNums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
