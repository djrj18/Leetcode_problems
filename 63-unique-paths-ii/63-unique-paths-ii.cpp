class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1] == 1){
            return 0;
        }
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        vector<vector<long long int>>dp(n,vector<long long int>(m));
        dp[n-1][m-1] = 1ll;
        for(int i = m-2;i>=0;i--){
            if(obstacleGrid[n-1][i] == 0){
                dp[n-1][i] = dp[n-1][i+1];
            }
            else{
                dp[n-1][i] = 0;
            }
        }
        for(int i = n-2;i>=0;i--){
            if(obstacleGrid[i][m-1] == 0){
                dp[i][m-1] = dp[i+1][m-1];
            }
            else{
                dp[i][m-1] = 0;
            }
        }
        
        for(int i = n-2;i>=0;i--){
            for(int j = m-2;j>=0;j--){
                if(obstacleGrid[i][j] == 0){
                    dp[i][j] = dp[i+1][j]+dp[i][j+1];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }
};