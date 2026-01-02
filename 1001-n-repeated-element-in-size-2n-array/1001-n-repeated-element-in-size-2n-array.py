class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        map = defaultdict(int)

        for i in range(len(nums)):
            map[nums[i]] += 1
        
        n = len(nums) // 2
        for key, value in map.items():
            if value == n:
                return key
        


        
            