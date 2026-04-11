class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        # [x, 1, 1]
        # [0, 1, 1]
        # [1, 0, 1]
        time = 0
        ROWS, COLS = len(grid), len(grid[0])
        q = deque()
        visited = set()
        count = 0

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 2:
                    q.append((r, c))
                    visited.add((r, c))
                if grid[r][c] == 1:
                    count += 1
        
        if count == 0:
            return time

        def bfs(r, c):
            nonlocal count
            if r < 0 or r == ROWS or c < 0 or c == COLS or grid[r][c] == 0 or (r, c) in visited:
                return
            q.append((r,c))
            visited.add((r,c))
            count -= 1

        while q and count > 0:
            for i in range(len(q)):
                r, c = q.popleft()
                grid[r][c] = 2
                bfs(r - 1, c)
                bfs(r + 1, c)
                bfs(r, c - 1)
                bfs(r, c + 1)
            time += 1

        return time if count == 0 else -1

