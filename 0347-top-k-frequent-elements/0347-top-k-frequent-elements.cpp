class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(auto &num : nums) {
            m[num]++;
        }
        map<int, vector<int>, greater<int>> freq;
        for(auto &[key, val] : m) {
            freq[val].push_back(key);
        }
        vector<int> res;
        for(auto &[key, val] : freq) {
            int n = val.size();
            k -= n;
            for(auto &v : val) res.push_back(v);
            if(k == 0) break;
        }
        return res;
    }
};