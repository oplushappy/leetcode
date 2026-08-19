class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magazineMap;
        for(auto c : magazine) {
            magazineMap[c] += 1;
        }

        for(auto c : ransomNote) {
            if(!magazineMap.count(c)) return false;
            if(magazineMap[c] < 1) return false;
            magazineMap[c] -= 1;
        }
        return true;
    }
};