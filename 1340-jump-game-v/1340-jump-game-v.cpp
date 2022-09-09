class Solution {
public:
    int solve(vector<int> &arr,int d, vector<int> &dp,int i){
        int n = arr.size();
        if(dp[i] != -1) return dp[i];
        dp[i] = 0;
       for(int j = i+1 ;j <= min(n-1,i+d) and arr[j] < arr[i] ; j++){
           dp[i] = max(dp[i], 1 + solve(arr,d,dp,j));
       }
       for(int j = i-1 ; j >= max(0,i-d) and arr[j] < arr[i] ; j--){
           dp[i] = max(dp[i], 1+solve(arr,d,dp,j));
       } 
       return dp[i];
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n,-1);
        int ans = 1;
        for(int i = 0 ; i < n ;i++) ans = max(ans, 1 + solve(arr,d,dp,i));
        return ans;
    }
};