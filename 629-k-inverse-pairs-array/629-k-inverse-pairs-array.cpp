class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int >> dp(n+1,vector<int>(k+1));
        int mod = 1000000007;
        dp[0][0] = 1;
        for(int i = 1 ; i <= n ;i++){
            long long int ans = 0ll;
            for(int j = 0 ; j <= k ;j++){
                    ans += (long long)dp[i-1][j];
                    if(j >= i){
                        ans -= (long long)dp[i-1][j-i];
                    }
                   
                    dp[i][j]  = ((long long)dp[i][j] + ans)%mod; 
                }
        }
        return dp[n][k];
    }
};