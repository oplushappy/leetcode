class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int res = 0;
        int s = intervals[0][0], e = intervals[0][1];
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] < e) {
                res++;
                if(intervals[i][1] < e) {
                    e = intervals[i][1];
                    s = intervals[i][0];
                }
            } else {
                e = max(e, intervals[i][1]);
            }
        }
        return res;
    }
};