class Solution {
public:
    string reverseWords(string s) {
        int l = 0, r = s.size() - 1;
        while (l <= r && s[l] == ' ') l++;
        while (r >= l && s[r] == ' ') r--;
        string cleanS = s.substr(l, r - l + 1);
        l = 0, r = 0;
        stack<string> st;
        while((r = cleanS.find(' ', l)) != string::npos) {
            st.push(cleanS.substr(l, r - l));
            while(cleanS[r] == ' ') r++;
            l = r;
        }
        st.push(cleanS.substr(l, cleanS.size() - l));
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) ans += ' ';
        }
        return ans;
    }
};