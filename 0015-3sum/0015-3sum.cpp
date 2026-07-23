class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<tuple<int, int, int>> s;
        for(int i = 0; i < n && nums[i] < 1; i++) {
            int target = -(nums[i]);
            int j = i + 1, k = n - 1;
            while(j < k) {
                int sum = nums[j] + nums[k];
                if(sum == target) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if(sum > target) {
                    k--;
                } else if(sum < target) {
                    j++;
                }
            }
        }
        vector<vector<int>> res;
        for(auto [t1, t2, t3] : s) {
            res.push_back({t1,t2,t3});
        }
        return res;
    }
};