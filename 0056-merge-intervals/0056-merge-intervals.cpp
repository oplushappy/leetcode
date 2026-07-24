class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for(int i = 1; i < n; i++) {
            int start = intervals[i][0], end = intervals[i][1];
            auto last_end = res.back()[1];
            if(last_end >= start) {
                res.back()[1] = max(end, last_end);
            } else {
                res.push_back({start, end});
            }
        }

        return res;
    }
};