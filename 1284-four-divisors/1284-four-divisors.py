class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        path = []
        for num in nums:
            tmp = []
            for i in range(1, int(num ** 0.5) + 1):
                if num % i == 0:
                    tmp.append(i)
                    if (num // i) != i:
                        tmp.append(num // i)
            path.append(tmp)
        
        ans = 0
        for numDiv in path:
            if len(numDiv) == 4:
                ans += sum(numDiv)
        
        return ans