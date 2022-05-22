class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int G = 0;G<n;G++){
            int i = 0;
            int j = G+i;
            while(j < n){
                if(G == 0){
                    dp[i][j] = 1;
                }
                else if(G== 1){
                    dp[i][j] = (s[i] == s[j]);
                }
                else{
                    if(s[i] == s[j] and dp[i+1][j-1]){
                        dp[i][j] = 1;
                    }
                }
                i++;j++;
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j  = 0;j<n;j++){
                if(dp[i][j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};