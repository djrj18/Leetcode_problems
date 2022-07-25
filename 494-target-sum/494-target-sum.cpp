class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        target = abs(target);
        vector<vector<int>> dp(n+1,vector<int>(2005,0));
        
        dp[n][0] = 1;
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = 0 ; j <= 1000 ;j++){
                dp[i][j] = dp[i+1][j+nums[i]]+dp[i+1][ abs(j - nums[i])];
            }
        }
        
        return dp[0][target];
    }
};