class Solution {
public:
    template<typename T, typename M>
    T get_first_match(T lo, T hi, M match) {
        while(lo <= hi) {
            T mid = lo + (hi - lo) / 2;
            if(match(mid)) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    };
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = get_first_match(0, m - 1, [&](int idx) {
            return matrix[idx][n - 1] >= target;
        });
        if(row == m) return false;
        if(target <  matrix[row][0]) return false;
        int col = get_first_match(0, n - 1, [&](int idx) {
            return matrix[row][idx] >= target;
        });
        if(matrix[row][col] != target) return false;
        return true;
    }
};