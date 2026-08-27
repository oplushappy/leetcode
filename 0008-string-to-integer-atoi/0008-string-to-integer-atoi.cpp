class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while(i < n && s[i] == ' ') i++;
        if(i == n) return 0;

        int sign = 1;
        if(s[i] == '+') i++;
        else if(s[i] == '-') {
            sign = -1;
            i++;
        }

        long long res = 0;
        while(i < n && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');
            if(sign * res <= INT_MIN) {
                return INT_MIN;
            }
            if(sign * res >= INT_MAX) {
                return INT_MAX;
            }
            i++;
        }

        return static_cast<int>(sign * res);
    }
};