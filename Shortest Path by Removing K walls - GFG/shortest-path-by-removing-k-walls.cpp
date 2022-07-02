// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,INT_MAX)));
        queue<pair<pair<int,int>,pair<int,int>>> q;
        q.push({{0,0},{0,0}});
        dp[0][0][0] = 0;
        while(q.size()){
            pair<pair<int,int>,pair<int,int>> p = q.front();
            q.pop();
            int dis = p.first.first;
            int wallsRemoved = p.first.second;
            int i = p.second.first;
            int j = p.second.second;
     
            int di[4] = {-1,1,0,0};
            int dj[4] = {0,0,-1,1};
            for(int t = 0 ; t < 4 ;t++){
                int ni = i+di[t];
                int nj = j+dj[t];
                if(ni >= 0 and nj >= 0 and ni < n and nj < m){
                    if(mat[ni][nj] == 1 and wallsRemoved != k and dp[ni][nj][wallsRemoved+1] > dis+1){
                        dp[ni][nj][wallsRemoved+1] = dis+1;
                        q.push({{dis+1,wallsRemoved+1},{ni,nj}});
                    }else if(mat[ni][nj] == 0 and dp[ni][nj][wallsRemoved] > dis+1){
                        dp[ni][nj][wallsRemoved] = dis+1;
                        q.push({{dis+1,wallsRemoved},{ni,nj}});
                    }
                }
            }
        }
        
        int ans = INT_MAX;
        for(int i = 0 ; i <= k ;i++){
            ans = min(ans,dp[n-1][m-1][i]);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends