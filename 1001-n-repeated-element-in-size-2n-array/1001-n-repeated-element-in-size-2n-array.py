class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        for i in range(len(nums) - 2):
            if nums[i] == nums[i + 1] or nums[i] == nums[i + 2]:
                return nums[i]
        
        # nums[-2], nums[-1], ex: [1, 2, 3, 3]
        return nums[-1]


        
            