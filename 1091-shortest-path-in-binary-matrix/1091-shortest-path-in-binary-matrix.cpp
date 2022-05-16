class Solution {
public:
    int solve(vector<vector<int>> &grid,int n,int m){
        int di[8] = {0,0,-1,-1,-1,1,1,1};
        int dj[8] = {-1,1,-1,0,1,-1,0,1};
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        while(q.size()){
            pair<int,pair<int,int>> p =q.front();
            q.pop();
            int i = p.second.first;
            int j = p.second.second;
            int d = p.first;
            for(int k = 0;k<8;k++){
                int ni = i+di[k];
                int nj = j+dj[k];
                if(ni >=0 and nj >=0 and ni < n and nj < m and grid[ni][nj] == 0){
                    if(ni == n-1 and nj == m-1){
                        return d+1;
                    }
                    q.push({d+1,{ni,nj}});
                    grid[ni][nj] = 1;
                }
            }
        }
        return INT_MAX;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 or grid[n-1][m-1] == 1){
            return -1;
        }
        if(n == 1 and m==1 and grid[0][0] == 0){
            return 1;
        }
        int ans = solve(grid,n,m);
        return ans == INT_MAX ? -1 : ans;
    }
};