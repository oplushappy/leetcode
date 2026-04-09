class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums) % 2 == 1:
            return False

        target = sum(nums) // 2
        dp = set()
        dp.add(0)

        for i in range(len(nums) - 1, -1, -1):
            newSet = set()
            for t in dp:
                newSet.add(t)
                newSet.add(t + nums[i])
            dp = newSet
        
        return True if target in dp else False