class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> dp(n,0);
        int i = 0;
        while(i < n-1){
            int cnt = 1;
            while(i < n-1 and ratings[i] < ratings[i+1]){
                dp[i] = cnt++; 
                i++;
            }
            dp[i] = cnt > 1 ? cnt : 0;
            i++;
        }
        dp[n-1] = dp[n-1] == 0 ? 1 : dp[n-1];
        for(int i = n-2 ; i >= 0 ;i--){
            if(dp[i] == 0){
                if(ratings[i] > ratings[i+1]){
                    dp[i] = dp[i+1]+1;
                }
                else{
                    dp[i] = 1;
                }
            }else{
                if(ratings[i] > ratings[i+1]){
                    dp[i] = max(dp[i],dp[i+1]+1);
                }
            }
        }
        
        int ans = 0;
        for(int i = 0 ; i < n;i++){
            ans += dp[i];
        }
        
        return ans;
        
    }
};