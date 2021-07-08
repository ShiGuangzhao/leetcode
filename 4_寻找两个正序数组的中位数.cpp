/*************************************************************************
    > File Name: 4_寻找两个正序数组的中位数.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年07月08日 星期四 12时54分22秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // merge
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tmp(nums1.size() + nums2.size());
        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), tmp.begin());
        auto half = tmp.size() / 2;
        return (tmp.size() % 2 != 0)? tmp[half]: (double(tmp[half]) + tmp[half - 1]) / 2;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto tmpSize = nums1.size() +nums2.size();
        int half = (tmpSize - 1) / 2;
        auto beg1 = nums1.begin(), beg2 = nums2.begin();
        double ret = 100000000;
        auto stop = (tmpSize % 2 != 0)? -1: -2;
        while(half-- > stop) {
            auto tmp = 0;
            if(beg1 == nums1.end()) {
                tmp = *beg2;
                ++beg2;
            }
            else if(beg2 == nums2.end()) {
                tmp = *beg1;
                ++beg1;
            }
            else {
                tmp = min(*beg1, *beg2);
                if(*beg1 > *beg2)   ++beg2;
                else                ++beg1;
            }
            if(half < 0)
                ret = (ret > 1000000)? tmp: (double(ret) + tmp) / 2;
        }
        return ret;
    }
};
