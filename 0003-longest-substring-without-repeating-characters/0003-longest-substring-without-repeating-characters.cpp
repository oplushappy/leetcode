class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int length = 0;
        unordered_set<char> sub;

        for(int r = 0; r < s.size(); r++) {
            while(sub.count(s[r])) {
                sub.erase(s[l]);
                l++;
            }
            sub.insert(s[r]);
            length = max(length, r - l + 1);
        }
        return length;
    }
};