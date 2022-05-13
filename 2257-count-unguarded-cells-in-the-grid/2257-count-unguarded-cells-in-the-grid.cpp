class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
       vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i = 0;i<walls.size();i++){
            visited[walls[i][0]][walls[i][1]] = 2;
        }
        for(int i = 0;i<guards.size();i++){
            visited[guards[i][0]][guards[i][1]] = 1;
        }
        
        for(int i = 0;i<guards.size();i++){
            int r = guards[i][0];
            int c = guards[i][1];
            visited[r][c] = 1;
            int k = r-1;
            while(k >=0 and visited[k][c] != 2 and visited[k][c] != 1){
                visited[k][c] = 3;
                k--;
            }
            k = r+1;
            while(k < m and visited[k][c] != 2 and visited[k][c] != 1){
                visited[k][c] = 3;
                k++;
            }
            k = c-1;
            while( k >=0 and visited[r][k] != 2 and visited[r][k] != 1){
                visited[r][k] = 3;
                k--;
            }
            k = c+1;
            while( k < n and visited[r][k] != 2 and visited[r][k] != 1){
                visited[r][k] = 3;
                k++;
            }
        }
        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(visited[i][j] == 0){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};