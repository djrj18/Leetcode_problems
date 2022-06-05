class Solution {
public:
    bool can_place(vector<vector<int>> Q,int r,int c,int n){
        for(int i = 0;i<r;i++){
            if(Q[i][c] == 1){
                return false;
            }
        }
        int i = r-1;
        int j = c-1;
        while(i >=0 and j >=0){
            if(Q[i][j] == 1){
                return false;
            }
            i--;
            j--;
        }
        i = r-1;
        j = c+1;
        while(i>=0 and j<n){
            if(Q[i][j] == 1){
                return false;
            }
            i--;
            j++;
        }
        
        return true;
    }
    void Can(vector<vector<int>>&Q,int n,int curr_row,int &ans){
        if(curr_row == n){
            ans++;
            return;
        }
        for(int i = 0;i<n;i++){
            bool t =  can_place(Q,curr_row,i,n);
            if(t){
                Q[curr_row][i] = 1;
                 Can(Q,n,curr_row+1,ans);
                Q[curr_row][i] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> Q(n,vector<int>(n,0));
        int ans = 0;
        Can(Q,n,0,ans);
        return ans;
    }
};