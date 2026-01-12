class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        ans = []
        path = []
        n = len(s)

        def dfs(i):
            if i == n:
                ans.append("".join(path))
                return

            c = s[i]

            if c.isalpha() and c.isascii():
                path.append(c.lower())
                dfs(i+1)
                path.pop()

                path.append(c.upper())
                dfs(i+1)
                path.pop()
            else:
                path.append(c)
                dfs(i+1)
                path.pop()

        dfs(0)
        return ans