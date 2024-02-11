class Solution {
public:
    int dp[80][80][80];
    int dfs(vector<vector<int>> &grid, int row, int col1, int col2) {
        if(row == grid.size()) return 0;
        int sum = 0;
        if(dp[row][col1][col2] != -1)
            return dp[row][col1][col2];
        for(int dir1 : {-1, 0, 1}) {
            int rob1_c = col1 + dir1;
            if(rob1_c >= 0 && rob1_c < grid[0].size()) { 
                for(int dir2 : {-1, 0, 1}) {
                    int rob2_c = col2 + dir2;
                    if(rob2_c >= 0 && rob2_c < grid[0].size())
                        sum = max(sum, dfs(grid, row + 1, rob1_c, rob2_c));
                }
            }
        }
        if(col1==col2){
            sum+=grid[row][col1];
        }
        else{
        sum += grid[row][col1] + grid[row][col2];
        }
        return dp[row][col1][col2] = sum;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return dfs(grid, 0, 0, col - 1);
    }
};