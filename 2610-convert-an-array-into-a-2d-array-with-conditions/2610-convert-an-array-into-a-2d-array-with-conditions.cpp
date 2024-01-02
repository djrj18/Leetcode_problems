class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        
        map<int,int> mp;
        int rowMin = 0;
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
            rowMin = max(rowMin, mp[nums[i]]);
        }
        
        vector<vector<int>> ans(rowMin);
        
        for(auto itr:mp){
            int i = 0;
            while(itr.second > 0){
                ans[i++].push_back(itr.first);
                itr.second--;
            }
        }
        return ans;
    }
};