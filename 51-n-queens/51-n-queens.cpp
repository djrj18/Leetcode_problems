class Solution {
public:
    bool Pos(vector<string> tillNow,int i,int c,int n){
        for(int r = 0 ; r < i ;r++){
            if(tillNow[r][c] == 'Q'){
                return false;
            }
        }
        
        int r = i;
        int cl = c;
        while( r >= 0 and cl >= 0){
            if(tillNow[r][cl] == 'Q'){
                return false;
            }
            r--;
            cl--;
        }
        r = i;
        cl = c;
        while( r >= 0  and cl < n){
            if(tillNow[r][cl] == 'Q'){
                return false;
            }
            r--;
            cl++;
        }
        return true;
    }
    void  solve(int n,vector<string> &tillNow,vector<vector<string>> &ans,int i){
        if(i == n){
            ans.push_back(tillNow);
            return;
        }
        
        for(int c = 0 ; c < n ;c++){
            if(Pos(tillNow,i,c,n)){
                tillNow[i][c] = 'Q';
                solve(n,tillNow,ans,i+1);
                tillNow[i][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string st = "";
        for(int i = 0 ; i < n ;i++){
            st += '.';
        }
        vector<string> tillNow(n,st);
              
        solve(n,tillNow,ans,0);
        return ans;
    }
};