class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int res = 0;
        int maxF = 0;
        vector<int> count(26, 0);
        for(int r = 0; r < s.size(); r++) {
            count[s[r] - 'A'] ++;
            maxF = *max_element(count.begin(), count.end());
            while((r - l + 1) - maxF > k) {
                count[s[l] - 'A']--;
                l++;
                // maxF = *max_element(count.begin(), count.end());
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};