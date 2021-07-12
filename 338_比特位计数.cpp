/*************************************************************************
    > File Name: 338_比特位计数.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年07月12日 星期一 17时48分31秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 暴力
    vector<int> countBits1(int n) {
        vector<int> ret{0};
        for(auto i = 1; i <= n; ++i) {
            uint32_t tmp = 0x80000000;
            int count = 0;
            while(tmp != 0) {
                if(tmp & i) ++count;
                tmp = tmp >> 1;
            }
            ret.push_back(count);
        }
        return ret;
    }

    // 000:0    0           2^0 - 1 == 0
    // 001:1    2 - 1       2^0 == 1
    // 010:1    2 - 1       
    // 011:2    2^2 - 1     所有2^n - 1 == n
    // 100:1    1           所有2^n == 1
    // 101:2    3 - 1       所有2^n + 1 = n - 1
    // 110:2    3 - 1       所有2^n + 2 = n - 1
    // 111:3    2^3 - 1
    vector<int> countBits(int n) {
        ++n;
        vector<int> ret(n, 0);
        int power = 1;
        int num = 1;
        while(num < n) {
            // cout << num << endl;
            auto stop = std::min(num, n - num);
            for(auto i = 0; i < stop; ++i) {
                ret[num + i] = power - ret[num - i - 1];
            }
            ++power;
            num *= 2;
        }
        return ret;
    }
};
