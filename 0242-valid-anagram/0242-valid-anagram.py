class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        map = defaultdict(int)
        for char in s:
            map[char] += 1

        for char in t:
            if char not in map : return False
            if not map[char] : return False
            map[char] -= 1
        if len(s) != len(t) : return False
        
        return True