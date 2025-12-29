class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        T = defaultdict(set)
        for u, v, w in allowed:
            T[u, v].add(w)

        memo = {}

        def dfs(row):
            if row in memo:
                return memo[row]

            if len(row) == 1:
                return True
            next_rows = []

            def backtrack(i, path):
                if i == len(row) - 1:
                    next_rows.append("".join(path))
                    return
                for w in T[row[i], row[i + 1]]:
                    path.append(w)
                    backtrack(i + 1, path)
                    path.pop()
            
            backtrack(0, [])

            for new_row in next_rows:
                if dfs(new_row):
                    memo[row] = True
                    return True
                    
            memo[row] = False
            return False

        return dfs(bottom)

            