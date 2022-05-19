class Solution {
public:
    int solve(vector<vector<int>> &mat,int i,int j,vector<vector<int>> &dp,int n,int m){
        if(dp[i][j] != -1){
            return dp[i][j]; 
        }
        
        int di[4] = {-1,1,0,0};
        int dj[4] = {0,0,-1,1};
        dp[i][j]  = 1;
        for(int k = 0;k<4;k++){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni >=0 and ni < n and nj >= 0 and nj < m and mat[ni][nj] > mat[i][j]){
                dp[i][j] = max(dp[i][j],solve(mat,ni,nj,dp,n,m)+1);
            }
        }
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 1;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(dp[i][j] == -1){
                    solve(matrix,i,j,dp,n,m);
                }
                ans = max(ans,dp[i][j]);
            }
        }
        
        return ans;
        
    }
};