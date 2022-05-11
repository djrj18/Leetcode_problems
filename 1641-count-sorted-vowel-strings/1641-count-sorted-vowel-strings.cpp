class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n,vector<int>(5));
        for(int i = 0;i<5;i++){
            dp[n-1][i] = 1;
        }
        
        for(int i = n-2;i>=0;i--){
            dp[i][0] = dp[i+1][0]+dp[i+1][1]+dp[i+1][2]+dp[i+1][3]+dp[i+1][4];
            dp[i][1] = dp[i+1][1]+dp[i+1][2]+dp[i+1][3]+dp[i+1][4];
            dp[i][2] = dp[i+1][2]+dp[i+1][3]+dp[i+1][4];
            dp[i][3] = dp[i+1][3]+dp[i+1][4];
            dp[i][4] = dp[i+1][4];
        }
        
        return dp[0][0]+dp[0][1]+dp[0][2]+dp[0][3]+dp[0][4];
    }
};