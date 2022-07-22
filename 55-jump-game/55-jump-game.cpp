class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxJump = 0;
        
        for(int i = 0 ; i < n ;i++){
             if(maxJump < i){
                return false;
            }
            maxJump = max(maxJump, i+nums[i]);
        }
        
        return true;
    }
};