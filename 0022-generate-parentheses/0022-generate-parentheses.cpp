class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string tmp;
        int left = 0, right = 0;
        auto backtrack = [&](auto &self) -> void {
            if(tmp.size() == (n * 2)) {
                res.push_back(tmp);
                return;
            } 
            
            if(left < n) {
                tmp += "(";
                left++;
                self(self);
                tmp.pop_back();
                left--;
            }
            if(left > right && right < n) {
                tmp += ")";
                right++;
                self(self);
                tmp.pop_back();
                right--;
            }
        };
        backtrack(backtrack);
        return res;
    }
};