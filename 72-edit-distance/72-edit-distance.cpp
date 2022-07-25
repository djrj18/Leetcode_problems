class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        dp[n][m] = 0;
        for(int i = m-1 ;i >= 0 ;i--){
            dp[n][i] = m - i;
        }
        for(int i = n-1 ; i >= 0 ;i--){
            dp[i][m] = n - i;
        }
        
        for(int i = n-1 ; i >= 0 ;i--){
            for(int j = m-1 ; j >= 0 ;j--){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    dp[i][j] = min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]}) + 1;
                }
            }
        }
        return dp[0][0];
    }
};