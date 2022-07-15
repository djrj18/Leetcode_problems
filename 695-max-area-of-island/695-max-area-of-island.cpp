class Solution {
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int &cnt, int n, int m){
        grid[i][j] = 0;
        cnt++;
        int di[4] = {0,0,-1,1};
        int dj[4] = {1,-1,0,0};
        for(int k = 0 ; k < 4; k++){
            int ni = di[k]+i;
            int nj = dj[k]+j;
            if(ni >= 0 and nj >= 0 and ni < n and nj < m and grid[ni][nj] == 1){
                dfs(grid,ni,nj,cnt,n,m);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ;j++){
                if(grid[i][j] == 1){
                    int cnt = 0;
                    dfs(grid,i,j,cnt,n,m);
                    ans = max(ans,cnt);
                }
            }
        }
        
        return ans;
        
    }
};