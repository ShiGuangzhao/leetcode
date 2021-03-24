/*************************************************************************
    > File Name: 50_POW_xn.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月24日 星期三 16时00分00秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
    double myPowPlus(double x, int64_t n) {
        if(n == 1) {
            return x;
        }
        else {
            auto half = myPowPlus(x, n/2);
            return (n % 2) == 0? half * half: half * half * x;
        }
    }

    double myPowPlus_LOOP(double x, int64_t n) {
        double ret = 1;
        double tmp = x;
        while(n > 0) {
            if((n % 2 ) == 1) {
                ret *= tmp;
            }
            tmp *= tmp;
            n /= 2;
        }
        return ret;
    }
public:
    double myPow(double x, int n) {
        if(x == 1 || x == 0) {
            return x;
        }
        if(n == 0) {
            return 1;
        }
        int64_t newN = n; 
        if(n < 0) {
            x = 1 / x;
            newN = -newN;
        }
        return myPowPlus_LOOP(x, newN);
    }
};

int main(void) {
    Solution s;
    cout << s.myPow(2, -2) << endl;
    cout << s.myPow(2, 2000000) << endl;
    cout << s.myPow(2, -2147483648) << endl;
}
