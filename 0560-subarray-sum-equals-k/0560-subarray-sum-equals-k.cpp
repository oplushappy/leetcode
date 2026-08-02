class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0;
        int ans = 0;
        unordered_map<int, int> s;
        s[0] = 1; 
        for(int i = 0; i < n; i++) {
            total += nums[i];
            auto it = s.find(total - k);
            if(it != s.end()) ans += it->second;
            s[total]++;
        }
        return ans;
    }
};