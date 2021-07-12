/*************************************************************************
    > File Name: 454_四数相加.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年07月09日 星期五 18时34分40秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // 暴力方法
    int fourSumCount1(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ret = 0;
        for(auto i = 0; i < nums1.size(); ++i) {
            for(auto j = 0; j < nums2.size(); ++j) {
                for(auto k = 0; k < nums3.size(); ++k) {
                    auto tmp = nums1[i] + nums2[j] + nums3[k];
                    for(auto h = 0; h < nums4.size(); ++h) {
                        if(tmp + nums4[h] == 0) ++ret;
                    }
                }
            }
        }
        return ret;
    }

    // 动态规划
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ret = 0;
        unordered_map<int, int> dp1, dp2, dp3;

        for(auto i: nums1) {
            if(dp1[i] != 0) {
                if(dp1[i] > 0) {
                    // cout << i << endl;
                    ret += dp1[i];
                }
                continue;
            }
            for(auto j: nums2) {
                auto ij = i + j;
                if(dp2[ij] != 0) {
                    if(dp2[ij] > 0) {
                        // cout << i << " " << j << endl;
                        ret += dp2[ij];
                        dp1[i] += dp2[ij];
                    }
                    continue;
                }
                for(auto k: nums3) {
                    auto ijk = ij + k;
                    if(dp3[ijk] != 0) {
                        if(dp3[ijk] > 0) {
                            // cout << i << " " << j << " " << k << endl;
                            ret += dp3[ijk];
                            dp2[ij] += dp3[ijk];
                            dp1[i] += dp3[ijk];
                        }
                        continue;
                    }
                    for(auto h: nums4) {
                        if(ijk + h == 0) {
                            // cout << i << " " << j << " " << k << " " << h << endl;
                            ++ret;
                            ++dp1[i];
                            ++dp2[ij];
                            ++dp3[ijk];
                        }
                    }
                    if(dp3[ijk] == 0) dp3[ijk] = -1;
                }
                if(dp2[ij] == 0) dp2[ij] = -1;
            }
            if(dp1[i] == 0) dp1[i] = -1;
        }
        // for(auto p: dp1) {
            // cout << "dp1" << p.first << " " << p.second << endl;
        // }
        // for(auto p: dp2) {
            // cout << "dp2" << p.first << " " << p.second << endl;
        // }
        // for(auto p: dp3) {
            // cout << "dp3" << p.first << " " << p.second << endl;
        // }
        return ret;
    }
};
