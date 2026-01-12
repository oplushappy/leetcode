class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        # (1, 0), (0, 1), (1, 1)
        cnt = 0
        distance = []
        for idx in range(len(points) - 1):
            dx = abs(points[idx][0] - points[idx + 1][0])
            dy = abs(points[idx][1] - points[idx + 1][1])
            distance.append([dx, dy])
        
        for dis in distance:
            diag = min(dis[0], dis[1])
            cnt += diag
            if dis[0] > diag:
                cnt += (dis[0] - diag)
            elif dis[1] > diag:
                cnt += (dis[1] - diag)
        
        return cnt

