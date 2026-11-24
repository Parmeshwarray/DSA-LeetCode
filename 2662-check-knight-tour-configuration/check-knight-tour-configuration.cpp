class Solution {
public:
    bool IsValid(vector<vector<int>>& grid, int row, int c,int n, int ExpVal){
        if(row < 0 || c < 0 || row >= n || c >= n || grid[row][c] != ExpVal){
            return false;
        }

        if(ExpVal == n*n-1){
            return true;
        }

        //8 possible moves
        int ans1 = IsValid(grid,row-2,c+1,n,ExpVal+1);
        int ans2 = IsValid(grid,row-1,c+2,n,ExpVal+1);
        int ans3 = IsValid(grid,row+1,c+2,n,ExpVal+1);
        int ans4 = IsValid(grid,row+2,c+1,n,ExpVal+1);
        int ans5 = IsValid(grid,row+2,c-1,n,ExpVal+1);
        int ans6 = IsValid(grid,row+1,c-2,n,ExpVal+1);
        int ans7 = IsValid(grid,row-1,c-2,n,ExpVal+1);
        int ans8 = IsValid(grid,row-2,c-1,n,ExpVal+1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return IsValid(grid, 0, 0, grid.size(), 0);
    }
};