class Solution {
public:
    bool solve(string s1,string s2,string s3,int i,int j,int k,vector<vector<vector<int>>> &dp){
        if(i == s1.length() and j == s2.length() and k == s3.length()){
            return true;
        }
        else if(i == s1.length()){
            while(j < s2.length() and k < s3.length()){
                if(s2[j] != s3[k]){
                    return false;
                }
                j++;
                k++;
            }
            return j == s2.length() and k == s3.length();
        }else if(j == s2.length()){
               while(i < s1.length() and k < s3.length()){
                if(s1[i] != s3[k]){
                    return false;
                }
                i++;
                k++;
            }
            return i == s1.length() and k == s3.length();
        }else if(k == s3.length()){
            return false;
        }
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        int ans = 0;
        if(s1[i] == s3[k]){
            ans |= solve(s1,s2,s3,i+1,j,k+1,dp);
        }
        if(s2[j] == s3[k]){
            ans |= solve(s1,s2,s3,i,j+1,k+1,dp);
        }
        
        return dp[i][j][k] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int l = s3.length();
        if(n+m != l){
            return false;
        }
       vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(l,-1)));
        return solve(s1,s2,s3,0,0,0,dp);
    }
};