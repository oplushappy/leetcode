class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        stack<char> st;
        auto isVowel = [&](char c) {
            return find(vowels.begin(), vowels.end(), c) != vowels.end();
        };
        for(auto const &c : s) {
            if(isVowel(c)) st.push(c);
        }
        for(auto &c : s) {
            if(isVowel(c)) {
                c = st.top(); 
                st.pop();
            }
        }
        return s;
    }
};