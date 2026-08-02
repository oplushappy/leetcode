class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int l = 0, r = 1; l < n && r < n;r++) {
            if(nums[l] && nums[r]) l++;
            if(nums[l] && nums[r] == 0) l++;
            if(nums[l] == 0 && nums[r]) {
                int tmp = nums[l];
                nums[l] = nums[r];
                nums[r] = tmp;
                l++;
            }
        }
    }
}; 