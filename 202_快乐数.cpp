/*************************************************************************
    > File Name: 202_快乐数.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月06日 星期日 23时10分37秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
    inline int power2(int n) {
        return n * n;
    }

public:
    // 直接计算，并设置表，表里面有自己就结束
    bool isHappy(int n) {
        unordered_set<int> happyed{n};
        while(n != 1) {
            int sum = 0;
            while(n != 0) {
                sum += power2(n % 10);
                n /= 10;
            }
            if(happyed.count(sum))  return false;
            happyed.insert(sum);
            n = sum;
        }
        return true;

    }
};
