class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(int G = 0 ; G < n ;G++){
            int i = 0 ;
            int j = G+i;
            while(j < n ){
                if(G == 0){
                    dp[i][j] = nums[i];
                    if(i > 0){
                        dp[i][j] *= nums[i-1];
                    }
                    if(j < n-1){
                        dp[i][j] *= nums[j+1];
                    }
                }
                else{
                    int finished = 1;
                    if(i > 0){
                        finished *= nums[i-1];
                    }
                    if(j < n-1){
                        finished *= nums[j+1];
                    }
                    for(int k = i ; k <= j ;k++){
                        int a = 0 , b = 0;
                        if(k != i){
                            a = dp[i][k-1];
                        }
                        if(k != j){
                            b = dp[k+1][j];
                        }
                        dp[i][j] = max(dp[i][j], a+b+finished*nums[k]);
                    }
                }
                j++;
                i++;
            }
        }
        return dp[0][n-1];
    }
};