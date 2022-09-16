class Solution {
public:
    int solve(vector<int> &nums,vector<int>&multipliers,int k,int i,vector<vector<int>>&dp){
        int n = nums.size();
        if(k == multipliers.size()) return 0;
        if(dp[i][k] != INT_MAX) return dp[i][k];
        
        return  dp[i][k] = max(solve(nums,multipliers,k+1,i+1,dp)+nums[i]*multipliers[k],solve(nums,multipliers,k+1,i,dp)+nums[n-1+i-k]*multipliers[k]);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,INT_MAX));
        return solve(nums,multipliers,0,0,dp);
        
    }
};