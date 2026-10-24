class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sCount(26, 0);
        vector<int> tCount(26, 0);
        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++) {
            sCount[s[i] - 'a']++;
            tCount[t[i] - 'a']++;
        }
        return sCount == tCount;
    }
};