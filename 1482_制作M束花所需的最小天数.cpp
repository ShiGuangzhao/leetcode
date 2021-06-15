/*************************************************************************
    > File Name: 1482_制作M束花所需的最小天数.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月10日 星期一 11时27分55秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m * k > bloomDay.size()) {
            return -1;
        }

        set<int> daySet;
        for(auto day: bloomDay) {
            daySet.insert(day);
        }
        auto nowDay = daySet.begin();
        while(nowDay != daySet.end()) {
            int count = 0;
            int flower = 0;
            for(auto &day: bloomDay) {
                if(day > *nowDay) {
                    flower += count / k;
                    count = 0;
                }
                else {
                    ++count;
                }
            }
            flower += count / k;
            if(flower >= m) {
                return *nowDay;
            }
            ++nowDay;
        }
        return -1;
    }
};
