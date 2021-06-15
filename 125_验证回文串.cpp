/*************************************************************************
    > File Name: 125_验证回文串.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月18日 星期二 19时23分04秒
 ************************************************************************/

#include <cctype>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int beg = 0;
        int end = s.size();
        while(end > beg) {
            while(!std::isalnum(s[beg])) {
                ++beg;
                if(end <= beg)  return true;
            }
            while(!std::isalnum(s[end])) {
                --end;
                if(end <= beg)  return true;
            }
            if(s[beg] != s[end] and
                    (!std::isalpha(s[beg]) or std::tolower(s[beg]) != std::tolower(s[end]))) {
                // cout << s[beg] << " " << s[end] << endl;
                return false;
            }
            ++beg;
            --end;
        }
        return true;
    }
};

int main(void) {
    Solution s;
    cout << std::boolalpha << s.isPalindrome("A man, a plan, a canal: Panama") << endl;;
}
