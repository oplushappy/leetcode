class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int len = min(m, n);
        string ans = "";
        int i = 0;
        for(; i < len; i++) {
            ans += word1[i];
            ans += word2[i];
        }
        ans += word1.substr(i);
        ans += word2.substr(i);
        return ans;
    }
};