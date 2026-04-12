class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        # p[k] = p[0] + p[1] + ... + p[i] + p[i+1] + ... + p[k]
        # sum(i+1, k) = p[k] - p[i]
        # hope sum(i+1, k) = 0
        # p[k] = p[i]

        diff = 0
        diff_index = {0:-1}
        res = 0

        for i, n in enumerate(nums):
            if n == 0:
                diff -= 1
            elif n == 1:
                diff += 1
            
            if diff in diff_index:
                res = max(res, i - diff_index[diff])
            else:
                diff_index[diff] = i
                
        return res