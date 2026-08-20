class Solution {
public:
    vector<string> m = {
        "",
        "",
        "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string tmp;
        int n = digits.size();
        auto backtrack = [&](auto &self, int pos) {
            if(tmp.size() == n) {
                res.push_back(tmp);
            }
            if(pos >= n) return;
            int mP = digits[pos] - '0'; 
            for(auto c : m[mP]) {
                tmp += c;
                self(self, pos + 1);
                tmp.pop_back();
            }
        }; 
        backtrack(backtrack, 0);
        return res;
    }
};