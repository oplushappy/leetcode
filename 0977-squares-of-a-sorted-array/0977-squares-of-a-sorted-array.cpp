class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int l = 0, r = nums.size() - 1;
        for(int i = r; i >= 0; i--) {
            if(abs(nums[l]) > abs(nums[r])) {
                res[i] = nums[l] * nums[l];
                l++;
            } else {
                res[i] = nums[r] * nums[r];
                r--;
            }
        }
        return res;
    }
};