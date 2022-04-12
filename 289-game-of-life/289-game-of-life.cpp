class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        
        int diri[8] = {0,-1,-1,-1,0,1,1,1};
        int dirj[8] = {-1,-1,0,1,1,1,0,-1};
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int alive = 0;
                for(int k = 0;k<8;k++){
                    if(i+diri[k] >=0 and i+diri[k] < n and j+dirj[k] >=0 and j+dirj[k] < m){
                        if(board[i+diri[k]][j+dirj[k]]){
                            alive++;
                        }
                    }
                }
          
                if(board[i][j]){
                    if(alive < 2 or alive > 3){
                        ans[i][j] = 0;
                    }
                    else{
                        ans[i][j] = 1;
                    }
                }
                else{
                    if(alive == 3){
                        ans[i][j] = 1;
                    }
                    else{
                        ans[i][j] = 0;
                    }
                }
            }

        }
        board = ans;
    }
};