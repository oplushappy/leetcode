class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        # sort 
        # [1,2], [1,3], [2,4], [3,4], [4,5]
        # find smaller always be right
        # [1,100] [2,3] [3,4]
        # [2, 4] [3, 4],[4, 5], [1,100]
        n = len(intervals)
        intervals.sort(key=lambda x: (x[1], x[0]))
        cnt = 1
        start, end = intervals[0]
        for i in range(1, n):
            if end <= intervals[i][0]:
                cnt += 1
                start, end = intervals[i]
        return n - cnt