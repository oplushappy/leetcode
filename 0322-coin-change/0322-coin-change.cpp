class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int total = 1; total <= amount; total++) {
            for(auto coin : coins) {
                if(coin <= total) {
                    dp[total] = min(dp[total], dp[total-coin] + 1);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};