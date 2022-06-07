class BFS{
private:
    vector<vector<int>>graph;
    vector<vector<int>>dis;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int row, col;
    
    bool isValid(int x,int y, vector<vector<int>> &vis){
        if(x<0 || x==row || y<0 || y==col || vis[x][y]!=INT_MAX || graph[x][y]==2)
            return false;
        return true;
    }
    
    int calculateTimesOfFireCatchingForEachCell(){
        queue<pair<int,int>>q;
        vector<vector<int>>vis = vector<vector<int>>(row, vector<int>(col,INT_MAX));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(graph[i][j]==1){
                    q.push({i,j});
                    vis[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto fr = q.front();
            q.pop();
            int x = fr.first;
            int y = fr.second;
            for(int i=0;i<4;i++){
                int nX = x + dx[i];
                int nY = y + dy[i];
                if(isValid(nX,nY,vis)){
                    q.push({nX,nY});
                    vis[nX][nY] = vis[x][y] + 1;
                }
            }
        }
        dis = vis;
        return 1;
    }
    bool isPossibleToReach(int time){
        queue<pair<int,int>>q;
        vector<vector<int>> vis = vector<vector<int>>(row, vector<int>(col,INT_MAX));
        q.push({0,0});
        vis[0][0] = time;
        while(!q.empty()){
            auto fr = q.front();
            q.pop();
            int x = fr.first;
            int y = fr.second;
            if(x==row-1 && y==col-1)
                return true;
            for(int i=0;i<4;i++){
                int nX = x + dx[i];
                int nY = y + dy[i];
                if(isValid(nX,nY,vis) && dis[nX][nY] > vis[x][y]+1 || (nX==row-1 && nY==col-1 && dis[nX][nY]>=vis[x][y]+1)){
                    q.push({nX,nY});
                    vis[nX][nY] = vis[x][y]+1;
                }
            }
        }
        return false;
    }
public:
    BFS(vector<vector<int>> &grid){
        this->graph = grid;
        this->row = grid.size();
        this->col = grid[0].size();
    }
    int maximumMinutes(){
        this->calculateTimesOfFireCatchingForEachCell();
        int low = 0, high = row*col+1,ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossibleToReach(mid)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans==row*col+1 ? 1e9 : ans;
        
    }
};
class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        BFS bfs(grid);
        return bfs.maximumMinutes();
    }
};