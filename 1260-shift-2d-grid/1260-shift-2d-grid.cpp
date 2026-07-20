class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        while(k--) {
            vector<int> tmp(m);
            for(int i = 0; i < m; i++) {
                tmp[i] = grid[i][n-1];
            }
            for(int i = 0; i < m; i++) {
                for(int j = n - 2; j >= 0; j--) {
                    grid[i][j + 1] = grid[i][j];
                }
            }
            for(int i = 0; i < m - 1; i++) {
                grid[i + 1][0] = tmp[i];
            }
            grid[0][0] = tmp[m - 1];
        }
        return grid;
    }
};