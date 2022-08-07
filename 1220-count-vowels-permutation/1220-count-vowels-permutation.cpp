class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long long int>> dp(n,vector<long long int>(5));
        string vwls = "aeiou";
        for(int i = 0 ; i < 5 ;i++){
            dp[n-1][i] = 1;
        }
        int mod = 1e9+7;
        for(int i = n-2 ; i >= 0 ;i--){
            for(int j = 0 ; j < 5 ;j++){
                if(j == 0){
                    dp[i][j] = dp[i+1][1];
                }
                else if(j == 1){
                    dp[i][j] = dp[i+1][0]+dp[i+1][2];
                    dp[i][j] %= mod;
                }
                else if(j == 2){
                    dp[i][j] = (dp[i+1][0]+dp[i+1][1]+dp[i+1][3]+dp[i+1][4]);
                    dp[i][j] %= mod;
                }
                else if(j == 3){
                    dp[i][j] = (dp[i+1][2]+dp[i+1][4]);
                    dp[i][j] %= mod;
                }
                else{
                    dp[i][j] = dp[i+1][0];
                }
            }
        }
        
        long long int ans = 0ll;
        for(int i = 0 ; i < 5 ;i++){
            ans += dp[0][i];
            ans %= mod;
        }
        return ans;
    }
};