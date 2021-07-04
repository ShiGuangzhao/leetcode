/*************************************************************************
    > File Name: 326_3的幂.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月28日 星期一 14时22分54秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0)  return false;
        int64_t pow = 1;
        while(pow < n) {
            pow *= 3;
        }
        return pow == n;
    }

    bool isPowerOfThree1(int n) {
        if(n == 0)  return false;
        while(n != 1) {
            if(n % 3 != 0)  return false;
            n /= 3;
        }
        return true;
    }
};

int main(void) {
    Solution s;
    cout << s.isPowerOfThree(45) << endl;
    cout << s.isPowerOfThree(1) << endl;
    cout << s.isPowerOfThree(27) << endl;
    return 0;
}
