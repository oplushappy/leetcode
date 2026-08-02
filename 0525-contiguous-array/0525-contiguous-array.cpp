class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = 0;
        int cnt = 0;
        m[0] = -1;
        for(int i = 0; i < nums.size(); i++) {
            cnt += nums[i] ? 1 : -1;
            auto it = m.find(cnt);
            if(it != m.end()) ans = max(ans, i - it->second);
            else m[cnt] = i;
        }
        return ans;
    }
};