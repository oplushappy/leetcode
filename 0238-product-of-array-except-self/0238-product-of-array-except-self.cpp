class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preffix(n);
        vector<int> suffix(n);
        int sum = 1;
        for(int i = 0; i < n; i++) {
            sum *= nums[i];
            preffix[i] = sum;
        }
        int backSum = 1;
        for(int i = n - 1; i >= 0; i--) {
            backSum *= nums[i];
            suffix[i] = backSum;
        }
        vector<int> res(n);
        res[0] = suffix[1];
        res[n-1] = preffix[n-2];
        for(int i = 1; i < (n - 1); i++) {
            res[i] = preffix[i-1] * suffix[i+1];
        }
        return res;
    }
};