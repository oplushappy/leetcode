class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        auto dp = vector(n, 0);
        dp[0] = nums[0];
        int maximum = dp[0];
        for(int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            maximum = max(maximum, dp[i]);
        }
        return maximum;
    }
};