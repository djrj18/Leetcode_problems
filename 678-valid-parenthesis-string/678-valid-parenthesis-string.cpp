class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
       vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        for(int G = 0 ; G < n ;G++){
            int i = 0;
            int j = G+i;
            while(j < n){
                if(G == 0){
                    dp[i][j] = s[i] == '*';
                }else if(G == 1){
                    if((s[i] == '(' or s[i] == '*') and (s[j] == ')' or s[j] == '*')){
                        dp[i][j] = true;
                    }
                }else{
                    
                    if((s[i] == '(' or s[i] == '*') and (s[j] == ')' or s[j] == '*')){
                        dp[i][j] = dp[i+1][j-1];
                    }
                    if(!dp[i][j]){
                    for(int k = i ; k < j ;k++){
                        dp[i][j] = dp[i][j] or (dp[i][k]&&dp[k+1][j]);
                    }
                    }
                    
                }
                i++;
                j++;
            }
        }
        return dp[0][n-1];
    }
};