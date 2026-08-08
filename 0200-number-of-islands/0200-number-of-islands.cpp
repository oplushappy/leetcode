class Solution {
public:
    vector<pair<int, int>> dirs = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    int numIslands(vector<vector<char>>& grid) {
        auto inside = [&](int x, int y) {
            return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
        };
        auto dfs = [&](auto &self, int x, int y) -> void {
            for(auto [dx, dy] : dirs) {
                int ddx = x + dx, ddy = y + dy;
                if(!inside(ddx, ddy)) continue;
                if(grid[ddx][ddy] == '0') continue;
                grid[ddx][ddy] = '0';
                self(self, ddx, ddy);
            }
            return;
        };
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(dfs, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};