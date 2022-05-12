class Solution {
public:
    void solve(vector<int> &nums,int start,vector<vector<int>> &ans){
        if(start == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        int i = start;
        map<int,int>visited;
        while(i < nums.size()){
            if(visited[nums[i]] == 0){
            swap(nums[i],nums[start]);
            solve(nums,start+1,ans);
            swap(nums[i],nums[start]);
            visited[nums[i]] = 1;
            }
            i++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,0,ans);
        return ans;
    }
};