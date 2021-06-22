/*************************************************************************
    > File Name: 5496_圆形赛道上经过次数最多的扇区.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年08月23日 星期日 10时47分46秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    void clacRound(map<int, int> &disk, int beg, int end, int n) {
        if(beg < end) {
            while(++beg <= end) {
                disk[beg]++;
            }
        }
        else {
            while(++beg <= n) {
                disk[beg]++;
            }
            beg = 0;
            while(++beg <= end) {
                disk[beg]++;
            }
        }
    }
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        map<int, int> disk;
        auto it = rounds.begin(); 
        disk[rounds[0]]++;
        while(it != rounds.end() - 1) {
            clacRound(disk, *it, *(++it), n);
        }
        vector<pair<int, int>> diskVec(disk.begin(), disk.end());
        sort(diskVec.begin(), diskVec.end(), \
                [](const pair<int, int> &a, const pair<int, int> &b) \
                {return a.second >= b.second;});
              // {return a.second == b.second? a.first < b.first: a.second > b.second;});
        auto beg = diskVec.begin();
        vector<int> ret{beg->first};
        while(++beg != diskVec.end() && beg->second == diskVec.begin()->second) {
            ret.push_back(beg->first);
        }
        return ret;
    }
};
