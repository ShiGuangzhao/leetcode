/*************************************************************************
    > File Name: 14_剪绳子2.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月31日 星期三 12时38分36秒
 ************************************************************************/

#include <iostream>
using namespace std;
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    // Wrong!
    // 动态规划
    // f(n) = f(x)*f(n-x)
    int cuttingRope1(int n) {
        if(n == 2) {
            return 1;
        }
        if(n == 3) {
            return 2;
        }
        vector<int> ret{0, 1};
        for(auto i = 2; i <= n; ++i) {
            uint64_t max = i;
            for(auto x = 1; x < i; ++x) {
                auto tmp = ((uint64_t)ret[x] * ret[i - x]) % 1000000007;
                if(tmp > max) {
                    max = tmp;
                }
            }
            ret.push_back(max);
        }
        return ret[n];
    }

    int cuttingRope(int n) {
        if(n <= 3) {
            return n - 1;
        }
        int th = n / 3;
        switch(n % 3) {
            case 0:
                return pow3(th);
            case 1:
                return (pow3(th - 1) * 4) % 1000000007;
            case 2:
                return (pow3(th) * 2) % 1000000007;
        }
        return 0;
    }

private:
    uint64_t pow3(int n) {
        if(n == 0) {
            return 1;
        }
        uint64_t half = pow3(n/2);
        // cout << half << endl;
        return (n % 2) == 1?
            (half * half * 3) % 1000000007:
            (half * half) % 1000000007;
    }
};

int main(void) {
    Solution s;
    cout << UINT32_MAX % 1000000007 << endl;
    cout << INT32_MAX % 1000000007 << endl;
    cout << s.cuttingRope(3) << endl;
    cout << s.cuttingRope(1000) << endl;
}
