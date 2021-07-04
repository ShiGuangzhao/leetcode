/*************************************************************************
    > File Name: 371_两整数之和.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年07月04日 星期日 11时42分08秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 位运算
    // 2 + 3 = 5
    // 010 + 011 = 101
    // -2 + 3 = 1
    // 1110 + 011 = 001
    int getSum1(int a, int b) {
        int ret = 0;
        int tmp = 0;
        for(auto bit = 0; bit < 32; ++bit) {
            auto bitA = (a >> bit) & 1;
            auto bitB = (b >> bit) & 1;
            auto bitRet = (bitA ^ bitB ^ tmp);
            ret |= (bitRet << bit);
            // ret 为 1，1/3，则三个都为1才需要进位
            // ret 为 0，0/2，则三个都为0才不需要进位
            if(bitRet) {
                if(!bitA or !bitB) {
                    tmp = 0;
                }
            }
            else {
                if(bitA or bitB) {
                    tmp = 1;
                }
            }
        }
        return ret;
    }

    int getSum(int a, int b) {
        int ret = a ^ b;    // 无进位加法
        int left = (unsigned int)(a & b) << 1;   // 需要进位的位
        while(left != 0) {
            auto tmp = ret ^ left;
            left = (unsigned int)(ret & left) << 1;
            ret = tmp;
        }
        return ret;
    }

};
