class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int target = 0;
        int n = nums.size();
        for(auto d : nums){
            target += d;
        }
        if(target % k != 0){
            return false;
        }
        target /= k;
        vector<int> dp((1<<n),-1);
        dp[0] = 0;
        
        for(int mask = 0 ; mask < (1<<n) ; mask++){
            if(dp[mask] == -1){
                continue;
            }
            
            for(int i = 0 ; i < n ;i++){
                if(!(mask & (1<<i)) and dp[mask]+nums[i] <= target){
                    dp[mask | (1<<i)] = (dp[mask]+nums[i])%target;
                }
            }
        }
        
        return dp[(1<<n) - 1] == 0;
    }
};