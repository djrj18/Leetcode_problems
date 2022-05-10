class Solution {
public:
    void solve(int start,int k,int n,vector<bool> &inc,vector<int> &tillNow,vector<vector<int>> &ans){
        if(k == 0 and n == 0){
            ans.push_back(tillNow);
            return;
        }
        else if(k == 0){
            return;
        }

        for(int i = start;i<=9;i++){
            if(i <= n){
                inc[i] = 1;
                tillNow.push_back(i);
                solve(i+1,k-1,n-i,inc,tillNow,ans);
                tillNow.pop_back();
                inc[i] = 0;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<bool> inc(10,0);
        vector<int> tillNow;
        vector<vector<int>> ans;
       solve(1,k,n,inc,tillNow,ans);
        return ans;
        
    }
};