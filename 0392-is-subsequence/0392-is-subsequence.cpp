class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = t.size(), n = s.size();
        if(!m && !n) return true;
        for(int sPos = 0, cur = 0; cur < m; cur++) {
            if(s[sPos] == t[cur]) sPos++;
            if(sPos == n) return true;
        }
        return false;
    }
};