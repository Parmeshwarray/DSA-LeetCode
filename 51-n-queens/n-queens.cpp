class Solution {
public:
    bool IsValid(vector<string> &board, int row, int n, int col){
        //horizontal
        for(int i=0; i<row; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        //vertical
        for(int j=0; j<col; j++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }

        //left-upper diagonal
        for(int i=row, j=col; i>=0 && j>=0; i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        //right-upper diagonal
        for(int i=row, j=col; i>=0 && j<n; i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }
    void NQueens (vector<string> &board, int row, int n, vector<vector<string>>& ans){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int j=0; j<n; j++){
            if(IsValid(board,row,n,j)){
                board[row][j] = 'Q';
                NQueens(board,row+1,n,ans);
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board (n, string(n, '.'));
        vector<vector<string>> ans;
        NQueens(board,0,n,ans);
        return ans;
    }
};