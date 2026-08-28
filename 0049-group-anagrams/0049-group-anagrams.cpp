class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> resMap;
        for(const string& str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            resMap[tmp].push_back(str);
        }
        vector<vector<string>> res;
        for(auto &[key, val] : resMap) {
            res.push_back(move(val));
        }
        return res;
    }
};