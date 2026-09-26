class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        set<vector<int>> s;
        for(int i = 0; i < n && nums[i] <= 0; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int cur = nums[i];
            int l = i + 1, r = n - 1;
            while(l < r) {
                int sum = nums[l] + nums[r] + cur;
                if(sum == 0) {
                    s.insert({cur, nums[l], nums[r]});
                    l++;
                    r--;
                } 
                else if(sum > 0) r--;
                else l++;
            } 
        }
        for(auto v : s) {
            res.push_back(v);
        }
        return res;
    }
};