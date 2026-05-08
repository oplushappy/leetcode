class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        n = len(nums)

        pre = [0] * n
        suf = [0] * n
        res = [0] * n

        # pre max
        pre[0] = nums[0]
        for i in range(1, n):
            pre[i] = max(nums[i], pre[i - 1])

        # suf min
        suf[-1] = nums[-1]
        for i in range(n - 2, -1, -1):
            suf[i] = min(nums[i], suf[i + 1])
        
        res[-1] = pre[-1]
        for i in range(n - 2, -1, -1):
            if pre[i] > suf[i + 1]:
                res[i] = res[i + 1]
            else:
                res[i] = pre[i]
        
        return res