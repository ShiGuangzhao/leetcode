/*************************************************************************
    > File Name: 53_最大子序和.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年08月26日 星期三 15时41分39秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// a[n], n = 0, 1, 2, n-1;
// 从0开始遍历，sum = 0, 大于则更新sum，否则sum = 0;
// 有可能全部小于0

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = 0x80000000;
        for(auto it = nums.begin(); it != nums.end(); ++it) {
            sum = max(*it, sum + *it);
            if(sum > maxSum)
                maxSum = sum;
            if(sum < 0)
                sum = 0;
        }
        return maxSum;
    }
};
