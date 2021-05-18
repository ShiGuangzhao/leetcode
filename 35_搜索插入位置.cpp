/*************************************************************************
    > File Name: 35_搜索插入位置.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月22日 星期一 13时55分53秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(auto it = nums.begin(); it < nums.end(); ++it) {
            if(*it == target || *it > target)
                return it - nums.begin();
        }
        return nums.size();
    }
};
