/*************************************************************************
    > File Name: 5_替换空格.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月17日 星期三 16时49分52秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string space{"%20"};
        int i = s.size() - 1;
        for(; i >= 0; --i) {
            if(s[i] == ' ')
                s.replace(i, 1, space);
        }
        return s;
    }
};

int main(void) {
    string test = "he llo";
        string space{"%20"};
    Solution s;
    cout << test << endl;
    s.replaceSpace(test);
    cout << test << endl;
}
