class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int total = 0;
        while(l < r) {
            total = tmp[l] + tmp[r];
            if(total == target) break; 
            else if(total > target) r--;
            else l++;
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(nums[i] == tmp[l] || nums[i] == tmp[r]) res.push_back(i);
        }
        return res;
    }
};