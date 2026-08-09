class Solution {
public:
    vector<pair<int, int>> dirs = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;

        queue<tuple<int, int, int>> q; // x, y, minutes
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.emplace(i, j, 0);
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if(fresh == 0) return 0;

        auto inside = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };
        while(!q.empty()) {
            auto [x, y, minutes] = q.front();
            q.pop();
            for(auto [dx, dy] : dirs) {
                int ddx = x + dx, ddy = y + dy;
                if(!inside(ddx, ddy)) continue;
                if(grid[ddx][ddy] == 0 || grid[ddx][ddy] == 2) continue;
                q.emplace(ddx, ddy, minutes + 1);
                grid[ddx][ddy] = 2;
                fresh--;
                if(fresh == 0) return minutes + 1;
            }
        }
        return -1;
    }
};