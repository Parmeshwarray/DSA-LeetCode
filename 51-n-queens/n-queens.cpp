class Solution {
public:

    bool IsSafe(vector<string>& board, int row, int col, int n){
        //horizontal
        for(int j=0; j<n; j++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }

        //vertical
        for(int i=0; i<n; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        //upper diagonal
        for(int i=row, j=col; i >= 0 && j>=0; i--, j-- ){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        //down diagonal
        for(int i=row, j=col; i >=0 && j<n; i--, j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        return true;
    }

    void NQueen(vector<string>& board, int n, int row, vector<vector<string>>& ans){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int j=0; j<n; j++){
            if(IsSafe(board,row,j,n)){
                board[row][j] ='Q';
                NQueen(board,n,row+1,ans);
                board[row][j]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n, '.'));

        NQueen(board, n, 0, ans);
        return ans;
    }
};