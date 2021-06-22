/*************************************************************************
    > File Name: 143_整数拆分.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月30日 星期四 13时01分39秒
 ************************************************************************/

#include <iostream>
// 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

class Solution {
public:
    int integerBreak(int n) {
        int C[n + 1];
        int M[n + 1];
        int temp;
        for(auto step = 1; step <= n; ++step) {
            C[step] = step;
            M[step] = 0;
            for(auto i = 1; i <= step/2; ++i) {
                temp = C[i] * C[step-i];
                if(temp > M[step]) {
                    M[step] = temp;
                }
            }
            if(M[step] > C[step]) {
                C[step] = M[step];
            }
        }
        return M[n];
    }
};
