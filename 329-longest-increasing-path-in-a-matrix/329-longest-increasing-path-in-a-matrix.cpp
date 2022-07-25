class Solution {
public:
    int  dfs(vector<vector<int>> &matrix,int i,int j ,vector<vector<int>> &dp,int n,int m){
        
        int di[4] = {-1,1,0,0};
        int dj[4] = {0,0,-1,1};
        int ans = 0;
        if(dp[i][j] != 0){
            return dp[i][j];
        }
        for(int k = 0 ; k < 4 ;k++){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni >= 0 and ni < n and nj >= 0 and nj < m and matrix[ni][nj] < matrix[i][j]){
                ans = max(ans, dfs(matrix,ni,nj,dp,n,m));
            }
        }
        
        return dp[i][j] = ans+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans = 1;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ;j++){
                if(dp[i][j] == 0){
                    dfs(matrix,i,j,dp,n,m);
                }
                ans = max(ans,dp[i][j]);
            }
        }
        
        return ans;
        
        
    }
};