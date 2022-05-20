class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> cnt2(n,vector<int>(m,0));
        vector<vector<int>> cnt5(n,vector<int>(m,0));
        vector<vector<pair<int,int>>> row(n,vector<pair<int,int>>(m));
        vector<vector<pair<int,int>>> col(m,vector<pair<int,int>>(n));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int cnt_2 = 0,cnt_5 = 0;
                while(grid[i][j]%2 == 0){
                    grid[i][j]/=2;
                    cnt_2++;
                }
                while(grid[i][j]%5 == 0){
                    grid[i][j]/=5;
                    cnt_5++;
                }
                cnt2[i][j] = cnt_2;
                cnt5[i][j] = cnt_5;
            }
        }
      
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(j == 0){
                    row[i][j] = {cnt2[i][j],cnt5[i][j]}; 
                }
                else{
                    row[i][j] = {row[i][j-1].first+cnt2[i][j],row[i][j-1].second+cnt5[i][j]};
                }
            }
        }
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(j == 0){
                    col[i][j] = {cnt2[j][i],cnt5[j][i]};
                }
                else{
                    col[i][j] = {col[i][j-1].first+cnt2[j][i],col[i][j-1].second+cnt5[j][i]};
                }
                
            }
           
        
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
               pair<int,int> a = {0,0},b,c,d;
               if(i != 0){
                   a = {col[j][i-1].first,col[j][i-1].second};
               }
               b = {row[i][j].first,row[i][j].second};
               c = {col[j][n-1].first-col[j][i].first,col[j][n-1].second-col[j][i].second};
               d = {row[i][m-1].first- (j == 0?0:row[i][j-1].first),row[i][m-1].second- (j == 0?0:row[i][j-1].second)}; 
                ans = max(ans,max({min(a.first+b.first,a.second+b.second),min(b.first+c.first,b.second+c.second),min(c.first+d.first,c.second+d.second),min(d.first+a.first,d.second+a.second)}));
                
            }
        }
         return ans;
        
    }
};