class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size();
        vector<uint32_t> dp(m + 1);
        dp[0] = 1;
        for(auto c : s) {
            for(int i = m - 1; i >= 0; i--) {
                if(c == t[i]) {
                    dp[i + 1] += dp[i];
                }
            }
        }
        return dp[m];
        
    }
};