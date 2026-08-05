class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        unordered_set<int> columns;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        for(auto row : rows) {
            for(auto &num : matrix[row]) num = 0;
        }
        for(auto col : columns) {
            for(auto &m : matrix) m[col] = 0;
        }
    }
};