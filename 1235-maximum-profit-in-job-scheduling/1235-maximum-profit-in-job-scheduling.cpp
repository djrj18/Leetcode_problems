class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> dp(n, vector<int>(2,0));
        vector<vector<int>> newArray(n);
        
        for(int i = 0 ; i < n ;i++) newArray[i] = {endTime[i], startTime[i], profit[i]};
        sort(newArray.begin(), newArray.end());
        sort(endTime.begin(), endTime.end());
        dp[0][0] = 0;
        dp[0][1] = newArray[0][2];

        int ans = 0;
        for(int i = 1 ; i < n ;i++){
            auto ind = upper_bound(endTime.begin(), endTime.begin() + i , newArray[i][1]);
            
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            
            int LastJobDone = ind - endTime.begin() - 1 ;
           
            if(LastJobDone >= 0) {
                dp[i][1] = max(dp[LastJobDone][0], dp[LastJobDone][1]) + newArray[i][2];
            }else{
                dp[i][1] = newArray[i][2];
            }
            
            ans = max(ans, max(dp[i][1], dp[i][0]));
        }
        
        return ans;
    }
};