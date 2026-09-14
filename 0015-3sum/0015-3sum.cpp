class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n && nums[i] <= 0; i++) {
            int l = i + 1, r = n - 1;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            if(i + 2 < n && nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
            int target = abs(nums[i]);
            while(l < r) {
                int sum = nums[l] + nums[r];
                if(sum == target) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l + 1]) l++;
                    l++;
                    r--;
                }
                else if(sum < target) l++;
                else r--;
            }
        }
        return res;
    }
};