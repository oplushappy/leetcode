class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int l = 0;
        int maxf = 0;
        unordered_map<char, int> ch_count;
        
        for(int r = 0; r < s.size(); r++) {
            ch_count[s[r]]++;
            maxf = max(maxf, ch_count[s[r]]);
            
            while(((r - l + 1) - maxf) > k) {
                ch_count[s[l]]--;
                l++;
            }
            res = max((r - l + 1), res);
        }
        return res;
    }
};