class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        ROWS = len(grid)
        COLS = len(grid[0])
        visited = set()
        island = 0

        def bfs(r, c) :
            q = deque()
            visited.add((r, c))
            q.append((r, c))

            direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]
            while q:
                row, col = q.popleft()
                for dr, dc in direction:
                    nr = row + dr
                    nc = col + dc
                    if (nr in range(ROWS) and
                        nc in range(COLS) and
                        grid[nr][nc] == "1" and
                        (nr, nc) not in visited) :
                        q.append((nr, nc))
                        visited.add((nr, nc))


        for r in range(ROWS):
            for c in range(COLS):
                if (grid[r][c] == "1" and  (r, c) not in visited) :
                    bfs(r, c)
                    island += 1
        
        return island
