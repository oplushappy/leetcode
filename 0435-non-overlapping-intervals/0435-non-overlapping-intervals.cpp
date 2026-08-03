class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int res = 0;
        int e = intervals[0][1];
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] < e) {
                res++;
                e = min(e, intervals[i][1]);
            } else {
                e = intervals[i][1];
            }
        }
        return res;
    }
};