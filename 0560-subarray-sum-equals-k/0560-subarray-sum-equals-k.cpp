class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cur = 0;
        int ans = 0;
        unordered_map<int, int> prefix;
        prefix[0] = 1; 
        for(int i = 0; i < n; i++) {
            cur += nums[i];
            // auto it = prefix.find(cur - k);
            // if(it != prefix.end()) ans += it->second;
            ans += prefix[cur - k];
            prefix[cur]++;
        }
        return ans;
    }
};