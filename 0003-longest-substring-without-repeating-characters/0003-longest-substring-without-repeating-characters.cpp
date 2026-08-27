class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        unordered_set<char> ss;
        int res = 0;
        for(int r = 0; r < s.size(); r++) {
            while(ss.count(s[r])) {
                ss.erase(s[l]);
                l++;
            } 
            ss.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};