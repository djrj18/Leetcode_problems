class Solution {
public:
    bool solve(string s1,string s2, string s3 ,int n,int m,int l ,int i ,int j ,int k,vector<vector<vector<int>>> &dp){
        if(i == n){
            while(j < m and k < l){
                if(s2[j] != s3[k]){
                    return false;
                }
                j++;
                k++;
            }
            return j == m and k == l;
        }
        if(j == m){
            while(i < n and k < l){
                if(s1[i] != s3[k]){
                    return false;
                }
                i++;
                k++;
            }
            return i == n and k == l;
        }
        if(k == l){
            return false;
        }
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        if(s1[i] == s3[k] and s3[k] == s2[j]){
            return dp[i][j][k] = solve(s1,s2,s3,n,m,l,i+1,j,k+1,dp) or solve(s1,s2,s3,n,m,l,i,j+1,k+1,dp);
        }
        else if(s1[i] == s3[k]){
            return dp[i][j][k] = solve(s1,s2,s3,n,m,l,i+1,j,k+1,dp);
        }
        else if(s2[j] == s3[k]){
            return dp[i][j][k] = solve(s1,s2,s3,n,m,l,i,j+1,k+1,dp);
        }
        
       return dp[i][j][k] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int l = s3.length();
         vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(l,-1)));
        
        return solve(s1,s2,s3,n,m,l,0,0,0,dp);
    }
};