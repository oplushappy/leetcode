class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), columns = matrix[0].size();
        int top = 0, bottom = rows - 1;

        while(top <= bottom) {
            int row = (top + bottom) / 2;
            if(target > matrix[row][columns - 1]) {
                top = row + 1;
            } else if(target < matrix[row][0]) {
                bottom = row - 1;
            } else {
                break;
            }
        }

        if(top > bottom) return false;
        
        int l = 0, r = columns - 1;
        int row = (top + bottom) / 2;
        // [[1]]
        while(l <= r) {
            int m = (l + r) / 2;
            if(target > matrix[row][m]) {
                l = m + 1;
            } else if(target < matrix[row][m]) {
                r = m - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};