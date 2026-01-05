class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        totalSum = 0
        minVal = float('inf')
        nCnt = 0

        for row in matrix:
            for val in row:
                totalSum += abs(val)
                if val < 0:
                    nCnt += 1
                minVal = min(minVal, abs(val))
        
        if nCnt % 2 == 1:
            totalSum -= minVal * 2
        
        return totalSum