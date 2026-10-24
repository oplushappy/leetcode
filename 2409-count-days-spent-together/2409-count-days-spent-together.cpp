class Solution {
    vector<int> Month = {
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        auto calacDay = [&](string s) {
            int total = 0;
            int m = stoi(s.substr(0, 2));
            int d = stoi(s.substr(3, 2));
            for(int i = 1; i < m; i++) {
                total += Month[i];
            }
            return total + d;
        };
        int arriveAliceDay = calacDay(arriveAlice);
        int leaveAliceDay = calacDay(leaveAlice);
        int arriveBobDay = calacDay(arriveBob);
        int leaveBobDay = calacDay(leaveBob);
        pair<int, int> Alice = {arriveAliceDay, leaveAliceDay};
        pair<int, int> Bob = {arriveBobDay, leaveBobDay};
        vector<pair<int, int>> days = {Alice, Bob};
        sort(days.begin(), days.end());
        if(days[1].first > days[0].second) return 0;
        else if(days[1].second < days[0].second) return days[1].second - days[1].first + 1;
        else return days[0].second - days[1].first + 1;
    }
};