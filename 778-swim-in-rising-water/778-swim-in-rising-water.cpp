class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1){
            return 0;
        }
        vector<vector<int>> visited(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        visited[0][0] = grid[0][0];
        pq.push({grid[0][0],{0,0}});
        while(pq.size()){
            pair<int,pair<int,int>> p = pq.top();
            pq.pop();
            int i = p.second.first;
            int j = p.second.second;
            int T = p.first;
            int di[4] = {-1,1,0,0};
            int dj[4] = {0,0,-1,1};
            for(int k = 0 ; k < 4 ;k++){
                int ni = i+di[k];
                int nj = j+dj[k];
                if(ni >= 0 and nj >= 0 and ni < n and nj < n and visited[ni][nj] > max(grid[ni][nj],T)){
                    visited[ni][nj] = max(grid[ni][nj],T);
                    pq.push({visited[ni][nj],{ni,nj}});
                }
            }
        }
        
        return visited[n-1][n-1];
        
    }
};