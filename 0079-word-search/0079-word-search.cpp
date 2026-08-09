class Solution {
public:
    vector<pair<int, int>> dirs = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.size();
        int m = board.size(), n = board[0].size();
        auto inside = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n; 
        };
        auto visited = vector(m, vector(n, false));
        auto dfs = [&](auto &self, int x, int y, int pos) {
            if(pos == len - 1) return true;

            for(auto [dx, dy] : dirs) {
                int ddx = x + dx, ddy = y + dy;
                if(!inside(ddx, ddy)) continue;
                if(visited[ddx][ddy]) continue;
                if(board[ddx][ddy] != word[pos + 1]) continue;
                
                visited[ddx][ddy] = true;
                if(self(self, ddx, ddy, pos + 1)) return true;
                visited[ddx][ddy] = false;
            }
            return false;
        };
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(len == 1) return true;
                    visited[i][j] = true;
                    if(dfs(dfs, i, j, 0)) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};