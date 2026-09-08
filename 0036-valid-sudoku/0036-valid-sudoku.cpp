class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        auto row = vector(9, vector(10, 0));
        auto col = vector(9, vector(10, 0));
        auto cell = vector(3, vector(3, vector(10, 0)));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if(row[i][num]) return false;
                if(col[j][num]) return false;
                if(cell[i/3][j/3][num]) return false;
                row[i][num]++;
                col[j][num]++;
                cell[i/3][j/3][num]++;
            }
        }
        return true;
    }
};