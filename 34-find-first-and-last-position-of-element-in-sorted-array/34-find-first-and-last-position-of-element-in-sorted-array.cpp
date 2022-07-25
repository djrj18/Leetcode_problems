class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ans = {-1,-1};
        
        int lind = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int up = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(lind < n and nums[lind] == target){
            ans[0] = lind;
            ans[1] = lind;
        }
        if(up > 0 and nums[up-1] == target){
            ans[1] = up-1;
        }
        
        return ans;
        
    }
};