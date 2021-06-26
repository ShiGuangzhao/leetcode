#include <iostream>

class Solution {
public:
    // 动态规划
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> dp(amount + 1, INT32_MAX);
        std::sort(coins.begin(), coins.end());
        if(amount < coins[0]) return -1;

        auto i = 0;
        dp[i++] = 0;
        while(i < coins[0]) dp[i++] = -1;
        dp[i] = 1;
        for(i = i + 1; i <= amount; ++i) {
            for(auto c: coins) {
                if(c > i) break;
                if(dp[i - c] == -1) continue;
                dp[i] = std::min(dp[i - c] + 1, dp[i]);
            }
            if(dp[i] == INT32_MAX) {
                dp[i] = -1;
            }
        }
        return dp.back();
    }
};
