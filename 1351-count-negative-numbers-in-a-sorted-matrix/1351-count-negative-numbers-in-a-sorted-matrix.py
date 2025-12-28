class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        # right 、 bottom is smallest
        # rightest > 0
        # bottom > 0
        m = len(grid)
        n = len(grid[0])
        negativeNums = 0
        for row in range(m - 1, -1, -1):
            if grid[row][-1] >= 0:
                break
            for column in range(n - 1, -1, -1):
                if grid[row][column] >= 0:
                    break
                if grid[row][column] < 0:
                    negativeNums += 1
        
        return negativeNums