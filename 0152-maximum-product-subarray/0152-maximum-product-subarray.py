class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = max(nums) # [-1]
        curMax, curMin = 1, 1

        for n in nums:
            temp = curMax * n
            curMax = max(curMax * n, curMin * n, n)
            curMin = min(temp, curMin * n, n)
            res = max(curMax, res)
        
        return res