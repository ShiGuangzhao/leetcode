/*************************************************************************
    > File Name: 1_两数之和.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年08月18日 星期二 19时09分15秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        vector<pair<int, int>> numsMap;
        for(auto n: nums) {
            numsMap.push_back({i++, n});
        }
        sort(numsMap.begin(), numsMap.end(), \
                [](pair<int, int> a, pair<int, int> b)->bool\
                {return a.second < b.second;});
        auto fun = bind(\
                [](pair<int, int> i, int range)->bool{return i.second > range;}, \
                std::placeholders::_1, target - numsMap.at(0).second);
        auto end = find_if(numsMap.begin(), numsMap.end(), fun);
        for(auto beg1 = numsMap.begin(); beg1 < end; ++beg1) {
            auto beg2 = find_if(beg1 + 1, end,\
                    bind([](pair<int, int> p, int value)->bool{return p.second == value;}, \
                        std::placeholders::_1, target - (*beg1).second));
            if(beg2 != end) {
                return {(*beg1).first, (*beg2).first};
            }
        }

        return {}; 
    }
};
