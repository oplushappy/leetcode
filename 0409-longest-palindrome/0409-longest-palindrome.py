class Solution:
    def longestPalindrome(self, s: str) -> int:
        c = Counter(s)
        
        length = 0
        flag = False
        
        for v in c.values():
            if v % 2 == 0 :
                length += v
            else :
                length += v - 1
                flag = True
        
        if flag : 
            length += 1

        return length