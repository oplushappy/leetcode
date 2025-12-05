class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        unordered_map<char, int> s1_count, s2_count;

        // init
        for(int i = 0; i < s1.size(); i++) {
            s1_count[s1[i]]++;
            s2_count[s2[i]]++;
        }

        int matches = 0;
        for(int i = 0; i < 26; i++) {
            if(s1_count[i + 'a'] == s2_count[i + 'a']) {
                matches++;
            }
        }

        int l = 0;
        for(int r = s1.size(); r < s2.size(); r++) {
            if(matches == 26) return true;
            s2_count[s2[r]]++;
            if(s1_count[s2[r]] == s2_count[s2[r]]) {
                matches++;
            } else if(s1_count[s2[r]] + 1 == s2_count[s2[r]]) { // original match, after add to be not matched
                matches--;
            }

            s2_count[s2[l]]--;
            if(s1_count[s2[l]] == s2_count[s2[l]]){
                matches++;
            } else if(s1_count[s2[l]] - 1 == s2_count[s2[l]]) {
                matches--;
            }
            l++;
        }
        return matches == 26;
    }
};