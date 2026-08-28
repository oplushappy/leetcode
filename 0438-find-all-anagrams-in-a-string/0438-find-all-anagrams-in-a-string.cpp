class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};

        vector<int> sMap(26, 0);
        vector<int> pMap(26, 0);
        int sLen = s.size(), pLen = p.size();
        for(int i = 0; i < pLen; i++) {
            sMap[s[i] - 'a'] ++;
        }
        for(int i = 0; i < pLen; i++) {
            pMap[p[i] - 'a'] ++;
        }

        vector<int> res;
        if(sMap == pMap) res.push_back(0);
        
        int l = 0;
        for(int r = pLen; r < sLen; r++) {
            sMap[s[r] - 'a'] ++;
            sMap[s[l] - 'a'] --;
            l++;
            if(sMap == pMap) res.push_back(l);
        }
        return res;
    }
};