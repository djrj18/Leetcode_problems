class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
  
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(target+1,INT_MAX)));
        if(houses[m-1] == 0){
        for(int i = 0 ; i < n ;i++){
            dp[m-1][i][1] = cost[m-1][i];
        }
        }else{
            dp[m-1][houses[m-1]-1][1] = 0;
        }
        
        
        for(int i = m-2 ; i >= 0 ; i--){
            for(int t = 1 ; t <= target ; t++){
                for(int currColor = 0 ; currColor < n ; currColor++){
                    int ans = INT_MAX;
                    for(int nextCol = 0; nextCol < n ;nextCol++){
                        if(houses[i] != 0){
                           if(nextCol == houses[i]-1){
                            dp[i][houses[i]-1][t] = dp[i+1][houses[i]-1][t];
                        }else{
                            ans = min(ans,dp[i+1][nextCol][t-1]);
                        }
                        }else{ 
                        if(nextCol == currColor){
                            dp[i][currColor][t] = dp[i+1][currColor][t];
                        }else{
                            ans = min(ans,dp[i+1][nextCol][t-1]);
                        }
                        }
                    }
                    if(houses[i] == 0){
                    dp[i][currColor][t] = min(ans,dp[i][currColor][t]);
                    if(dp[i][currColor][t] != INT_MAX){
                        dp[i][currColor][t] += cost[i][currColor];
                    }
                    }else{
                        dp[i][houses[i]-1][t] = min(ans,dp[i][houses[i]-1][t]);
                        break;
                    }
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0 ; i < n ;i++){
            ans = min(ans,dp[0][i][target]);
        }
        
        return ans == INT_MAX ? -1 : ans;
        
    }
};