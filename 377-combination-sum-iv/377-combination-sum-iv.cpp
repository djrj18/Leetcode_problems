class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned int> ans(target+1,0);
        ans[0] = 1;
        for(int i = 1 ; i <= target ;i++){
            for(int j = 0 ; j < n ; j++){
                if(nums[j] <= i and ans[i - nums[j]] != 0){
                    ans[i] += ans[i-nums[j]];
                }
            }
        }
        
        return ans[target];
        
    }
};