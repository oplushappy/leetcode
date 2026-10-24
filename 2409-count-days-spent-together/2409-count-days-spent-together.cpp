class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> Month = {
            0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
        };
        vector<int> prefix(13);
        partial_sum(Month.begin(), Month.end(), prefix.begin());
        auto dayOfYear = [&](const string& s) {
            int m = (s[0] - '0') * 10 + (s[1] - '0');
            int d = (s[3] - '0') * 10 + (s[4] - '0');
            return prefix[m - 1] + d;
        };
        int start = max(dayOfYear(arriveAlice), dayOfYear(arriveBob));
        int end = min(dayOfYear(leaveAlice), dayOfYear(leaveBob));
        return max(0, end - start + 1);
    }
};