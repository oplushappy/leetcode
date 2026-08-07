class Solution {
public:
    vector<pair<int, int>> dirs = {
        {1, 0}, {-1, 0}, {0, -1}, {0, 1}
    };
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        auto inside = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };
        queue<tuple<int, int, int>> q;
        auto visited = vector(m, vector(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    q.emplace(i, j, 0);
                    visited[i][j] = true;
                } 
            }
        }
        auto res = vector(m, vector(n, 0));
        while(!q.empty()) {
            auto [x, y, step] = q.front();
            q.pop();
            res[x][y] = step;
            for(auto [dx, dy] : dirs) {
                int ddx = x + dx, ddy = y + dy;
                if(!inside(ddx, ddy)) continue;
                if(visited[ddx][ddy]) continue;
                visited[ddx][ddy] = true;
                q.emplace(ddx, ddy, step + 1);
            }
        }
        return res;
    }
};