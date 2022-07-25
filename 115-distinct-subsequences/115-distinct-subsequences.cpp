class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.length();
        int n=t.length();
        if(m==0 and n!=0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        unsigned long int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
            for(int i=m;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(j==n){
                    dp[i][j]=1;
                }
                else if(i==m){
                    dp[i][j]=0;
                }
                else{
                    if(s[i]==t[j]){
                        dp[i][j]=dp[i+1][j+1]+dp[i+1][j];
                    }
                    else{
                        dp[i][j]=dp[i+1][j];
                    }
                }
            }
        }
        return dp[0][0];
        
    }
};