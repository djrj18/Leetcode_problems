class Solution {
public:
    long long int dfs(int m ,int n,vector<vector<vector<long long int>>> &paths,int i,int j,int maxMove){
        if(i >= m or i < 0 or j >= n or j < 0){
       
            return 1ll;
        }
        if(maxMove == 0){
            return 0ll;
        }
        if(paths[i][j][maxMove] != -1){
            return paths[i][j][maxMove];
        }
        int ans = 0ll;
        int mod = 1000000007;
        int di[4] = {0,0,-1,1};
        int dj[4] = {-1,1,0,0};
        for(int k = 0 ; k < 4 ;k++){
            int ni = i+di[k];
            int nj = j+dj[k];
               
                ans += dfs(m,n,paths,ni,nj,maxMove-1);
          
                ans %= mod;
        }
        return paths[i][j][maxMove] = ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long long int>>> paths(m,vector<vector<long long int>>(n,vector<long long>(maxMove+1,-1)));
       
        
       dfs(m,n,paths,startRow,startColumn,maxMove);

        
        int ans = paths[startRow][startColumn][maxMove];
        return ans == -1 ? 0 : ans;
    }
};