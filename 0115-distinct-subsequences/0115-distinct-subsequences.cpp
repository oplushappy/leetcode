class Solution {
    const int inf = INT_MIN / 2;
public:
    int numDistinct(string s, string t) {
        int m = t.size();
        vector<unsigned int> dp(m+1, 0);
        dp[0] = 1;
        for(auto c : s) {
            for(int i = m; i > 0; i--) {
                if(c == t[i - 1]) {
                    dp[i] += dp[i-1];
                }
            }
        }
        return dp[m];
    }
};