class Solution {
public:
    int ROWS, COLS;
     vector<vector<bool>> visited;

    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        visited = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));

        for(int i = 0 ; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(dfs(0, i, j, board, word)) return true;
            }
        }
        return false;
    }
    bool dfs(int i, int row, int column, vector<vector<char>>& board, string& word) {
        if(i == word.size()) {
            return true;
        }
        if(row >= ROWS || column >= COLS || row < 0 || column < 0 || word[i] != board[row][column] || visited[row][column]) {
            return false;
        }

        visited[row][column] = true;
        bool result = (dfs(i + 1, row + 1, column, board, word) || 
                    dfs(i + 1, row - 1, column, board, word) ||
                    dfs(i + 1, row, column + 1, board, word) ||
                    dfs(i + 1, row, column - 1, board, word));
        visited[row][column] = false;

        return result;
    }
};