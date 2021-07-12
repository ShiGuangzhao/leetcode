/*************************************************************************
    > File Name: 1195_交替打印字符串.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年07月12日 星期一 14时22分23秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class FizzBuzz {
private:
    int n;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        if(n % 3 == 0) {
            printFizz();
        }

    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        if(n % 5 == 0) {
            printBuzz();
        }

    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        if(n % 15 == 0) {
            printFizzBuzz();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        if(n % 3 != 0 and n % 5 != 0) {
            printNumber(n);
        }
    }
};
