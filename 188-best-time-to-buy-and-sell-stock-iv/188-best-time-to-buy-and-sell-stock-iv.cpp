class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        vector<vector<int>> dp(k+1, vector<int> (n,0));
        
        for(int i = 1 ; i <= k ;i++){
            int max_diff = -prices[0];
            for(int j = 1 ; j < n ;j++){
                dp[i][j] = max(dp[i][j-1], max_diff + prices[j]);
                max_diff = max(max_diff, dp[i-1][j] - prices[j]);
            }
            
        }
        return dp[k][n-1];
    }
};