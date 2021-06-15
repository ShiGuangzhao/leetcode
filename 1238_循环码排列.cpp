/*************************************************************************
    > File Name: 1238_循环码排列.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年04月08日 星期四 14时06分11秒
 ************************************************************************/

#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 格雷码为：
    // 000
    // 001
    // 011
    // 010
    // 110
    // 111
    // 101
    // 100
    vector<int> circularPermutation(int n, int start) {
        vector<int> ret((1 << n), 0);
        step = (1 << (n - 1));
        setBits(ret.begin() + step, ret.end());
        step = step >> 1;
        while(step > 0) {
            for(auto beg = ret.begin(); beg != ret.end(); beg += (step << 2)) {
                setBits(beg + step, beg + step * 3);
            }
            step = step >> 1;
        }
        auto startIn = std::find(ret.begin(), ret.end(), start);
        vector<int> cycleRet(startIn, ret.end());
        cycleRet.insert(cycleRet.end(), ret.begin(), startIn);
        return cycleRet;
        // return ret;
    }

    // 格雷码和二进制码转换
    // G = B ^ (B >> 1)
    // B = ^(G >> i)
	vector<int> circularPermutation2(int n, int start) {
        vector<int> ret{start};
        int beg = start;
        while(start >>= 1) {
            // 赋值表达式返回右值，因此start == 1时退出循环
            beg ^= start;   // 计算start对应的二进制码
        }
        int stop = (1 << n);
        for(auto i = beg + 1; i < stop; ++i) {
            ret.push_back(i ^ (i >> 1));
        }
        for(auto i = 0; i < beg; ++i) {
            ret.push_back(i ^ (i >> 1));
        }
        return ret;
    }

private:
    int step;
    inline void setBits(vector<int>::iterator beg, vector<int>::iterator end) {
        while(beg != end) {
            *beg++ |= step;
        }
    }
};

int main(void) {
    auto print = [](vector<int> v) {
        for(auto it = v.begin(); it != v.end(); ++it) {
            cout << *it << endl;
        }
    };
    Solution s;
    auto v = s.circularPermutation2(1, 1);
    print(v);
}

