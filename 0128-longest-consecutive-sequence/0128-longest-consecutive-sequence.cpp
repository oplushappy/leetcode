class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto &num : nums) {
            s.insert(num);
        }
        int ans = 0;
        for(auto val : s) {
            if(s.count(val - 1)) continue;
            int i = val;
            int length = 1;
            while(s.count(++i)) length++;
            ans = max(ans, length);
        }
        return ans;
    }
};