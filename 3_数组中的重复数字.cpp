/*************************************************************************
    > File Name: 3.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月12日 星期五 16时53分54秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int findSame(vector<int> &num) {
    std::set<int> numCount;
    for(auto i: num) {
        if(numCount.find(i) == numCount.end()) {
            numCount.insert(i);
        }
        else {
            return i;
        }
    }
    return -1;
}

int main(void) {
    vector<int> n{2, 3, 5, 6, 3, 5, 6};
    cout << findSame(n) << endl;
}
