class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for(int cur = 0; cur < t.size() && i < s.size(); cur++) {
            if(s[i] == t[cur]) i++;
        }
        return i == s.size();
    }
};