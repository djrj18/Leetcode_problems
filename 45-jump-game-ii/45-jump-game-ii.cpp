class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[n-1] = 0;
        for(int i = n-2 ; i >= 0 ;i--){
            dp[i] = INT_MAX;
            for(int j = i+1; j <= min(i+nums[i],n-1) ;j++){
                if(dp[j] != INT_MAX){
                dp[i] = min(dp[i],dp[j]+1);
                }
            }
        }
        
        return dp[0];
    }
};