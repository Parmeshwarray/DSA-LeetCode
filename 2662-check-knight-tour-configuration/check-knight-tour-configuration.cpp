class Solution {
public:
    bool IsValid(vector<vector<int>>& grid, int row, int col, int n, int ExpVal){
        if(row < 0 || col < 0 || row >= n || col >= n || grid[row][col] != ExpVal){
            return false;
        }

        if(grid[row][col] == n*n-1){
            return true;
        }

        int ans1 = IsValid(grid,row-2,col+1,n,ExpVal+1);
        int ans2 = IsValid(grid,row-1,col+2,n,ExpVal+1);
        int ans3 = IsValid(grid,row+1,col+2,n,ExpVal+1);
        int ans4 = IsValid(grid,row+2,col+1,n,ExpVal+1);
        int ans5 = IsValid(grid,row+2,col-1,n,ExpVal+1);
        int ans6 = IsValid(grid,row+1,col-2,n,ExpVal+1);
        int ans7 = IsValid(grid,row-1,col-2,n,ExpVal+1);
        int ans8 = IsValid(grid,row-2,col-1,n,ExpVal+1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 ||ans8 ;

    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return IsValid(grid,0,0,grid.size(),0);
    }
};