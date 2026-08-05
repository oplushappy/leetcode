class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // int n = board.size(), m = board[0].size();
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        auto block = vector(3, vector<unordered_set<int>>(3));

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if(rows[i].count(num) || cols[j].count(num) || block[i/3][j/3].count(num)) {
                    return false;
                } else {
                    rows[i].insert(num);
                    cols[j].insert(num);
                    block[i/3][j/3].insert(num);
                }
            }
        }
        return true;
    }
};