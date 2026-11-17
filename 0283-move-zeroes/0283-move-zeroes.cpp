class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 1;
        while(l < n && r < n) {
            if(nums[l] == 0 && nums[r] == 0) {
                r++;
                continue;
            } else if(nums[l] == 0) {
                swap(nums[l], nums[r]);
            }
            l++;
            r++;
        }
    }
};