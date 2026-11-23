
class Solution {
public:
    bool IsSafe(int n, vector<string>& board, int row, int col) {

        // vertical
        for(int i = 0; i < n; i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }

        // horizontal
        for(int j = 0; j < n; j++) {
            if(board[row][j] == 'Q') {
                return false;
            }
        }

        // upper-left diagonal
        for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {

            if(board[i][j] == 'Q') {
                return false;
            }
        }

        // upper-right diagonal
        for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {

            if(board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void NQueens(int n, vector<string>& board, int row, vector<vector<string>>& ans) {

        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int j = 0; j < n; j++) {

            if(IsSafe(n, board, row, j)) {

                board[row][j] = 'Q';

                NQueens(n, board, row+1, ans);

                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        vector<vector<string>> ans;

        NQueens(n, board, 0, ans);

        return ans;
    }
};
