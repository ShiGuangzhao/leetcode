/*************************************************************************
    > File Name: a.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年08月19日 星期三 15时43分11秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

void setVector(vector<int> &v, int num) {
    cout << num << endl;
    while(num != 0) {
        v.push_back(num % 10);
        num /= 10;
    }
}

int reverse(int x) {
    int ret = 0;
    vector<int> str, maxNum;
    if(x == (1 << 31)) {
        return 0;
    }
    setVector(str, x > 0? x: -x);
    setVector(maxNum, (1 << 30) - 1 + (1 << 30));
    cout << maxNum.size() << "   " << str.size() << endl;
    if(maxNum.size() < str.size()) {
        return 0;
    }
    else if(maxNum.size() == str.size()) {
        auto mbeg = maxNum.rbegin();
        for(auto sbeg = str.begin(); sbeg != str.end(); ++sbeg, ++mbeg) {
            if(*sbeg > *mbeg) {
                return 0;
            }
            else if(*sbeg < *mbeg){
                break;
            }
        }
    }
    for(auto sbeg = str.begin(); sbeg != str.end(); ++sbeg) {
        ret = ret*10 + *sbeg;
    }
    return x > 0? ret: -ret;
}

int main(void) {
    auto i = 2147483647;
    std::cout << i << std::endl;
    std::cout << reverse(i) << std::endl;
    // std::cout << 1534236469 << std::endl;
    // std::cout << reverse(1534236469) << std::endl;
    return 0;
}
