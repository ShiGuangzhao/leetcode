/*************************************************************************
    > File Name: 122_买股票的最佳时机2.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月14日 星期五 21时13分56秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int low = prices[0];
        int i = 1;
        while(1) {
            while(i < prices.size()) {
                if(prices[i] > prices[i - 1]) {
                    break;
                }
                ++i;
            }
            low = prices[i - 1];
            while(i < prices.size() and prices[i] > prices[i - 1]) {
                ++i;
            }
            if(i >= prices.size()) {
                ret += prices[i - 1] - low;
                return ret;
            }
            else {
                ret += prices[i - 1] - low;
                low = prices[i++];
            }
        }
    }
};
