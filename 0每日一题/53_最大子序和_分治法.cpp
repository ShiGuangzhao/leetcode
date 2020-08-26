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
// 分治法：0 -- n/2, 1 + n/2 -- n-1
// 左边最大值，右边最大值，旁边测的最大值

class Solution {
private:
    void devide(vector<int> &nums, int &maxSum, int &sideMaxSum) {

    }
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
