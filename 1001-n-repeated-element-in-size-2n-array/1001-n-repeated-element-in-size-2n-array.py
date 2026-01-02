class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        s = len(nums)
        n = s // 2
        map = defaultdict(list)
        nums.sort()
        for i in range(s - 1):
            cnt = 1
            while nums[i] == nums[i + 1]:
                i += 1
                cnt += 1
                if i == s - 1:
                    break
            map[cnt].append(nums[i])
        
        return map[n][0]

        
            