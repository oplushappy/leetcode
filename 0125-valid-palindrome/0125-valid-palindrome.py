class Solution:
    def isPalindrome(self, s: str) -> bool:        
        res = [char.lower() for char in s if char.isalnum()]
        res = "".join(res)
        
        return res == res[::-1]
        