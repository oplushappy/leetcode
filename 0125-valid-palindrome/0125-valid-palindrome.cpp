class Solution {
public:
    bool isPalindrome(string s) {
        string tmp = "";
        for(auto c : s) {
            if(isalnum(c)) tmp += tolower(c);
        }
        int l = 0, r = tmp.size() - 1;
        while(l < r) {
            if(tmp[l] != tmp[r]) return false;
            l++, r--;
        }
        return true;
    }
};