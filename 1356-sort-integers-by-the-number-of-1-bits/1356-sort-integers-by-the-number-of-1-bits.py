class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        ansMap = defaultdict(list)
        for num in arr:
            size = bin(num).count('1')
            ansMap[size].append(num)
        
        ans = []
        for idx, v in sorted(ansMap.items()):
            ans.extend(sorted(v))

        return ans


        