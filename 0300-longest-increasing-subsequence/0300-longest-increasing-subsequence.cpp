class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n);
        dp[n-1] = 1;
        int as = 1;
        for(int i = n-2 ; i >= 0; i--){
            int ans = 1;
            for(int j = i+1 ; j < n ;j++){
                if(nums[j] > nums[i]) ans = max(ans, dp[j]+1);
            }
            dp[i] = ans;
            as = max(as, dp[i]);
        }
        
        return as;
    }
};