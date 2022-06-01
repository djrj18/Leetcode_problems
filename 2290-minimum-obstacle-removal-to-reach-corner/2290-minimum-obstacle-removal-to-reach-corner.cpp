class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,10000007));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        if(grid[0][0] == 1){
            pq.push({1,{0,0}});
        }
        else{
            pq.push({0,{0,0}});
        }
        visited[0][0] = grid[0][0];
        while(pq.size()){
            pair<int,pair<int,int>> p = pq.top();
            pq.pop();
            int i = p.second.first;
            int j = p.second.second;
            if(i == n-1 and j == m-1){
                return p.first;
            }
            int di[4] = {0,0,-1,1};
            int dj[4] = {1,-1,0,0};
            for(int k = 0 ;k < 4 ;k++){
                int ni = i+di[k];
                int nj = j+dj[k];
                if(ni >= 0 and ni < n and nj >= 0 and nj < m and visited[ni][nj] > grid[ni][nj]+p.first){
                visited[ni][nj] = grid[ni][nj]+p.first;
                    pq.push({visited[ni][nj],{ni,nj}});
                }
            }
        }
        
        return INT_MAX;
        
    }
};