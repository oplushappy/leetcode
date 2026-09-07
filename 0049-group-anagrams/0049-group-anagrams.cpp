class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(auto &str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(str);
        }
        vector<vector<string>> res;
        for(auto &[key, val] : m) {
            res.push_back(move(val));
        }
        return res;
    }
};