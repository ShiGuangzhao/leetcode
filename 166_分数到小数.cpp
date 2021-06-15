/*************************************************************************
    > File Name: 166_分数到小数.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月30日 星期日 14时07分12秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // 这个做法不太对
    string fractionToDecimal(int numerator, int denominator) {
        string ret;
        double result = double(numerator) / denominator;
        if(result < 0) {
            ret.push_back('-');
            result = -result;
        }
        ret += std::to_string(int(result));
        result -= int(result);
        string after_points;
        while(result != 0 and after_points.size() < 10000) {
            result *= 10;
            after_points.push_back(int(result) + '0');
            result -= int(result);
        }
        if(after_points.size() == 0) {
            return ret;
        }
        if(result == 0) {
            ret.push_back('.');
            ret += after_points;
        }
        else {
            auto tmp = denominator;
            ret.push_back('.');
            auto beg = after_points.begin();
            while((tmp % 10) == 0 and beg != after_points.end()) {
                ret.push_back(*beg);
                ++beg;
                tmp /= 10;
            }
            after_points = after_points.substr(
                    beg - after_points.begin(), after_points.end() - beg);
            
            // 8/3 = 2.666666
            // 8/30 = 0.266666
            // 1/3 = 0.33333
            // 10/3 = 3.3333
            // 1/30 = 0.033333
            // 需要考虑以上情况
            // 需要考虑如何计算循环

        }
        return ret;
    }
};
