class Solution {
public:

    bool helper(vector<vector<char>>& board, int row, int col,int idx, string &word) {

        int rows = board.size();
        int cols = board[0].size();

        // Invalid position
        if (row < 0 || col < 0 || row >= rows || col >= cols || board[row][col] == '#'){
            return false;
        }

        // Character does not match
        if (board[row][col] != word[idx]) {
            return false;
        }

        // Last character matched
        if (idx == word.length() - 1) {
            return true;
        }

        // Save original character
        char original_value = board[row][col];

        // Mark as visited
        board[row][col] = '#';

        // Try all 4 directions
        bool found = 
            helper(board, row + 1, col, idx + 1, word) || // Down
            helper(board, row - 1, col, idx + 1, word) || // Up
            helper(board, row, col - 1, idx + 1, word) || // Left
            helper(board, row, col + 1, idx + 1, word);   // Right

        // Backtrack
        board[row][col] = original_value;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        // Try every cell as starting point
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (board[i][j] == word[0]) {

                    if (helper(board, i, j, 0, word)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};