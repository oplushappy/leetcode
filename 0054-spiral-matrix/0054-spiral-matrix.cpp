class Solution {
public:
    vector<pair<int, int>> dirs = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size(), m = matrix[0].size();
        auto dfs = [&](auto &self, int row, int col, int r, int c, int dr, int dc) {
            if(row == 0 || col == 0) return;
            for(int i = 0; i < col; i++) {
                r += dr;
                c += dc;
                res.push_back(matrix[r][c]);
            }
            self(self, col, row - 1, r, c, dc, -dr);
        };
        dfs(dfs, n, m, 0, -1, 0, 1);
        return res;
    }
};