class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        # (1, 0), (0, 1), (1, 1)
        cnt = 0
        for idx in range(len(points) - 1):
            curX, curY = points[idx]
            tarX, tarY = points[idx + 1]
            cnt += max(abs(tarX - curX), abs(tarY - curY))
        
        return cnt

