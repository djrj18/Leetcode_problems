class Solution {
public:
    
    int countSubstrings(string s) {
           
        int n = s.length();
            vector<vector<bool>> dp(n,vector<bool>(n));
        for(int i=0;i<n;i++){
            dp[i][i] = true;
        }
        for(int L=2;L<=n;L++){
            for(int i=0;i+L<=n;i++){
                int j = i + L - 1;
                if(L==2){
                    dp[i][j] = s[i]==s[j];
                }
                else if(s[i]==s[j] and dp[i+1][j-1]){
                    dp[i][j] = true;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                ans += dp[i][j];
            }
        }
        return ans;
    }
    };