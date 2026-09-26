class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < n && nums[i] <= 0; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int cur = nums[i];
            int l = i + 1, r = n - 1;
            while(l < r) {
                int sum = nums[l] + nums[r] + cur;
                if(sum == 0) {
                    res.push_back({cur, nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l - 1]) l++;
                    while(r > 0 && (r + 1) < n && nums[r] == nums[r + 1]) r--;
                } 
                else if(sum > 0) r--;
                else l++;
            } 
        }
        return res;
    }
};