class Solution:
    def longestPalindrome(self, s: str) -> int:
        c = Counter(s)
        total = 0
        odd = 0
        flag = False
        for v in c.values():
            if v % 2 == 0 :
                total += v
            else :
                total += v - 1
                flag = True
        if flag : total += 1

        return total