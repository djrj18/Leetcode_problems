class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i = 0 ; i < n ;i++){
            auto itr = lower_bound(dp.begin(), dp.end(), nums[i]);
            if(itr == dp.begin()) dp[0] = nums[i];
            else if(itr == dp.end()) dp.push_back(nums[i]);
            else{
                dp[itr - dp.begin()] = nums[i];
            }
            
        }
        
        return dp.size();
    }
};