class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<map<long long int,long long int>> dp(n);
        long long int ans = 0ll;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ;j++){
                long long int diff = (long)nums[i] - (long)nums[j];
                
                if(dp[j].find(diff) != dp[j].end()){
                    ans += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
                
                dp[i][diff] += 1;
            }
        }
        return ans;
    }
}; 