/*************************************************************************
    > File Name: 350_两个数组的交集2.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年07月04日 星期日 11时27分16秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // map
    vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;
        vector<int> ret;
        for(auto i: nums1) {
            ++count[i];
        }
        for(auto i: nums2) {
            if(count.find(i) != count.end() and count[i] != 0) {
                ret.push_back(i);
                --count[i];
            }
        }
        return ret;
    }

    // sort
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        vector<int> ret;
        auto beg1 = nums1.begin();
        auto beg2 = nums2.begin();
        while(beg1 != nums1.end() and beg2 != nums2.end()) {
            if(*beg1 == *beg2) {
                ret.push_back(*beg1);
                ++beg1;
                ++beg2;
            }
            else if(*beg1 < *beg2) {
                ++beg1;
            }
            else {
                ++beg2;
            }
        } 
        return ret;
    }
};
