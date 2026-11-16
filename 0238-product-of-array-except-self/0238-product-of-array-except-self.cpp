class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        partial_sum(nums.begin(), nums.end(), prefix.begin(), multiplies<>());
        partial_sum(nums.rbegin(), nums.rend(), suffix.begin(), multiplies<>());
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                ans[i] = suffix[n - i - 2];
            } else if(i == n - 1) {
                ans[i] = prefix[n - 2];
            } else {
                ans[i] = prefix[i - 1] * suffix[n - i - 2];
            }
        }
        return ans;
    }
};