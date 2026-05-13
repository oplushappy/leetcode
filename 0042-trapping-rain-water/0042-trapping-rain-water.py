class Solution:
    def trap(self, height: List[int]) -> int:
        # 0 1 0 2 1 0 1 3 2 1 2 1
        # 0 1 1 2 2 2 2 3 3 3 3 3
        # 3 3 3 3 3 3 3 3 2 2 2 1
        n = len(height)
        prefix = [0] * n
        suffix = [0] * n
        maxV = 0
        for i in range(n):
            if height[i] > maxV:
                maxV = height[i]
            prefix[i] = maxV
        
        maxV = 0
        for i in range(n - 1, -1, -1):
            if height[i] > maxV:
                maxV = height[i]
            suffix[i] = maxV
        
        ans = 0
        for i, h in enumerate(height):
            if h < prefix[i] and h < suffix[i]:
                ans += min(prefix[i], suffix[i]) - h
        
        return ans

