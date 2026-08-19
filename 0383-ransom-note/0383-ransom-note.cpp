class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magazineMap;
        for(auto c : magazine) {
            magazineMap[c] += 1;
        }

        for(auto c : ransomNote) {
            if(--magazineMap[c] < 0) return false;
        }
        return true;
    }
};