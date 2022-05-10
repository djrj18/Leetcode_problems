class Solution {
public:
    int dp[100][100][500];
    int dfs(vector<vector<char>> &grid,int i,int j,int n,int m,int k){
        if(i >= n or j>= m){
            return 0;
        }
        if(grid[i][j] == ')'){
            k--;
        }
        else{
            k++;
        }
        if(i == n-1 and j == m-1){
            return k == 0 ? 1 : 0;
        }
        
        if(k < 0){
            return 0;
        }
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        int ans1 = dfs(grid,i+1,j,n,m,k);
        if(ans1){
            return dp[i][j][k] = 1;
        }
        int ans2 = dfs(grid,i,j+1,n,m,k);
        return dp[i][j][k] = ans2;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp)); 
        return dfs(grid,0,0,n,m,0);
        
    }
};