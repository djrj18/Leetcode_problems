class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1));
        dp[n][m] = true;
        for(int i = 0 ; i < m ;i++){
            dp[n][i] = false;
        }
        for(int i = n-1; i >= 0; i--){
            if(i < n-1 and p[i+1] == '*'){
                dp[i][m] = dp[i+1][m];
            }
            else if(p[i] == '*'){
                dp[i][m] = dp[i+1][m];
            }
            else{
                dp[i][m] = false;
            }
        }
        
        for(int i = n-1 ; i >= 0 ;i--){
            for(int j = m-1 ; j >= 0 ;j--){
                if(i < n-1 and p[i+1] == '*'){
                    dp[i][j] = dp[i+1][j];
                }
                else  if(p[i] == s[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else if(p[i] == '.'){
                    dp[i][j] = dp[i+1][j+1];
                }
                else if(p[i] == '*'){
                    dp[i][j] = dp[i+1][j] or (dp[i][j+1] and (p[i-1] == s[j] or p[i-1] == '.'));
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        // for(int i = 0 ; i <= n ; i++){
        //     for(int j = 0 ; j <= m ;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[0][0];
    }
};