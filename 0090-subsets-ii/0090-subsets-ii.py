class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        def backTrack(i, subset):
            if i == len(nums):
                res.append(subset.copy())
                return
            
            # include nums[i]
            subset.append(nums[i])
            backTrack(i + 1, subset)
            subset.pop()

            # skip nums[i]
            while i + 1 < len(nums) and nums[i] == nums[i+1]:
                i += 1
            backTrack(i + 1, subset)
        
        backTrack(0, [])
        return res