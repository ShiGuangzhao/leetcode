/*************************************************************************
    > File Name: 412_FizzBuzz.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年07月09日 星期五 14时07分31秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define SOLUTION_PUSH_BACK(_RET, _N, _I, _STR)      \
    if(_I > _N) break;                              \
    _RET.push_back(_STR);

class Solution {
public:
    // 暴力解法
    vector<string> fizzBuzz1(int n) {
        vector<string> ret;
        bool div3, div5;
        for(auto i = 1; i <= n; ++i) {
            div3 = (i % 3 == 0);
            div5 = (i % 5 == 0);
            if(div3 and div5) {
                ret.push_back("FizzBuzz");
            }
            else if(div3) {
                ret.push_back("Fizz");
            }
            else if(div5) {
                ret.push_back("Buzz");
            }
            else {
                ret.push_back(std::to_string(i));
            }
        }
        return ret;
    }
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        for(auto i = 1; i <= n; ++i) {
            ret.push_back(to_string(i));
            SOLUTION_PUSH_BACK(ret, n, ++i, to_string(i))
            SOLUTION_PUSH_BACK(ret, n, ++i, "Fizz")
            SOLUTION_PUSH_BACK(ret, n, ++i, to_string(i))
            SOLUTION_PUSH_BACK(ret, n, ++i, "Buzz")
            SOLUTION_PUSH_BACK(ret, n, ++i, "Fizz")
            SOLUTION_PUSH_BACK(ret, n, ++i, to_string(i))
            SOLUTION_PUSH_BACK(ret, n, ++i, to_string(i))
            SOLUTION_PUSH_BACK(ret, n, ++i, "Fizz")
            SOLUTION_PUSH_BACK(ret, n, ++i, "Buzz")
            SOLUTION_PUSH_BACK(ret, n, ++i, to_string(i))
            SOLUTION_PUSH_BACK(ret, n, ++i, "Fizz")
            SOLUTION_PUSH_BACK(ret, n, ++i, to_string(i))
            SOLUTION_PUSH_BACK(ret, n, ++i, to_string(i))
            SOLUTION_PUSH_BACK(ret, n, ++i, "FizzBuzz")
        }
        return ret;
    }
};
