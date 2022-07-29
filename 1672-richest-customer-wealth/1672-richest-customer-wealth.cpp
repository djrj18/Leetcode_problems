class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_amount=0;
        vector<int>sum(accounts.size());
        for(int i=0;i<accounts.size();i++){
        for(int j=0;j<accounts[i].size();j++){
      sum[i]+=accounts[i][j];
            max_amount=max(max_amount,sum[i]);
        }
           // max_amount=max(max_amount,sum[i]);
        }
        return max_amount;
    }
};