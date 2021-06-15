/*************************************************************************
    > File Name: 121_买股票的最佳时机.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月10日 星期一 14时17分36秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 暴力求解会超出时间限制
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        auto beg = prices.begin();
        while(beg < prices.end() - 1) {
            auto sale = std::max_element(beg + 1, prices.end());
            // beg = std::min_element(beg, sale);
            ret = std::max(*sale - *beg, ret);
            // beg = sale + 1;
            beg = std::find_if(beg, prices.end(), [beg](int a) {return a < *beg;});
        }
        return ret;
    }
};

int main(void) {
    Solution s;
    vector<int> nums{3,2,6,5,0,3};
    cout << s.maxProfit(nums) << endl;
}
