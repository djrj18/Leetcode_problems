class Solution {
public:
    void dfs(vector<vector<char>> &grid,int i,int j,vector<vector<int>> &visited){
        visited[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int di[4] = {0,0,-1,1};
        int dj[4] = {-1,1,0,0};
        for(int k = 0 ;k < 4 ;k++){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni >=0 and nj >= 0 and ni < n and nj < m  and grid[ni][nj] == '1' and visited[ni][nj] == 0){
                dfs(grid,ni,nj,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int ans = 0;
        
        for(int i = 0 ;i < n ;i++){
            for(int j = 0 ;j < m ;j++){
                if(grid[i][j] == '1' and visited[i][j] == 0){
                    ans++;
                    dfs(grid,i,j,visited);
                }
            }
        }
        return ans;
    }
};