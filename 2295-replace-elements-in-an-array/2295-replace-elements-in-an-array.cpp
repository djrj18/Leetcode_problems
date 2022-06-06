class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n = nums.size();
        int m = operations.size();
        map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]] = i;
        }
        
        for(int i = 0 ; i < m ;i++){
            int a = operations[i][0];
            int b = operations[i][1];
            int id = mp[a];
            mp.erase(a);
            mp[b] = id;
        }
        int si = mp.size();
        vector<int> ans(si);
       for(auto data: mp){
           ans[data.second] = data.first;
       }
        return ans;
        
    }
};