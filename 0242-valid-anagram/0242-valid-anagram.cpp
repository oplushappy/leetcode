class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sM(26, 0);
        vector<int> tM(26, 0);
        for(auto &c : s) {
            sM[c - 'a']++;
        }
        for(auto &c : t) {
            tM[c - 'a']++;
        }
        return sM == tM;
    }
};