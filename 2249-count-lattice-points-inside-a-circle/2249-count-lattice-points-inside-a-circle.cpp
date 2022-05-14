class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        vector<vector<int>> mat(205,vector<int>(205,0));
        
        for(int i = 0;i<circles.size();i++){
            int xc = circles[i][0];
            int yc = circles[i][1];
            int r = circles[i][2];
            for(int x = xc-r;x<=xc+r;x++){
                for(int y = yc-r;y<=yc+r;y++){
                    if((x-xc)*(x-xc)+(y-yc)*(y-yc) <= r*r){
                        mat[x][y] = 1;
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i = 0;i<205;i++){
            for(int j = 0;j<205;j++){
                if(mat[i][j] == 1){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};