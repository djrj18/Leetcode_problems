class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
       int ns = strs.size();
        vector<vector<vector<int>>> dp(ns,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        int ans = 0;
        for(int i = 0;i<ns;i++){
            int cnt0 = 0,cnt1 = 0;
            for(int j = 0;j<strs[i].length();j++){
                if(strs[i][j] == '0'){
                    cnt0++;
                }
                else{
                    cnt1++;
                }
            }
            for(int j = 0;j<=m;j++){
                for(int k = 0;k<=n;k++){
                    if(j >= cnt0 and k >= cnt1){
                        dp[i][j][k] = max(dp[i][j][k],1);
                        if(i > 0){
                            dp[i][j][k]  = max(dp[i][j][k],max(dp[i-1][j-cnt0][k-cnt1]+1,dp[i-1][j][k]));
                        }
                    }
                    else if(i!=0){
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                   
                }
            }
        }
        return dp[ns-1][m][n];
    }
};