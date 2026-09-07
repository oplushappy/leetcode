class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto &num : nums) {
            m[num]++;
        }
        vector<vector<int>> freq(nums.size() + 1);
        for(auto &[key, val] : m) {
            freq[val].push_back(key);
        }
        vector<int> res;
        for(int i = freq.size() - 1; i >= 0; i--) {
            for(auto &v : freq[i]) {
                res.push_back(v);
            }
            if(res.size() == k) break;
        }
        return res;
    }
};