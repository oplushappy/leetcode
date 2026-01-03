class Solution:
    def numOfWays(self, n: int) -> int:
        MOD = 1000000007
        x, y = 6, 6

        for i in range(2, n + 1):
            new_x = (x * 3 + y * 2) % MOD
            new_y = (x * 2 + y * 2) % MOD
            x, y = new_x, new_y
        
        return (x + y) % MOD
