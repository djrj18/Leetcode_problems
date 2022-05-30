class Solution {
public:
    int solve(vector<int> &arr,int rem,int curr,vector<vector<int>> &dp,vector<int> &ans){
        if(rem == 0 or curr == arr.size()){
            return 0;
        }
        if(dp[curr][rem] != -1){
            return dp[curr][rem];
        }
        
        int Exc = solve(arr,rem,curr+1,dp,ans);
        int Inc = 0;
        if(rem >= arr[curr]+1){Inc = solve(arr,rem - (arr[curr]+1),curr+1,dp,ans)+curr;}
        if(Inc > Exc){
            ans[curr] = arr[curr]+1;
        }
        return dp[curr][rem] = max(Inc,Exc);
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int ass = 0;
        vector<int> ans(12);
        for(int i = 0;i<pow(2,12);i++){
            vector<int> t(12,0);
            int tans = 0;
            int cnt = 0;
            for(int j = 0;j<12;j++){
                if(i&(1<<j)){
                    t[11-j] = aliceArrows[11-j]+1;
                    tans += (11-j);
                    cnt += t[11-j];
                }
            }
            if(cnt == numArrows){
                if(tans > ass){
                    ass = tans;
                    ans = t;
                }
            }
            else if(cnt < numArrows){
                t[11] += numArrows-cnt;
                if(tans >ass){
                    ass= tans;
                    ans = t;
                }
            }
        }
        return ans;
    }
};