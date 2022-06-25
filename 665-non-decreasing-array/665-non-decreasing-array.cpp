class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool mila = false;
        bool ans = true;
        int prev = nums[0];
        int n = nums.size();
        for(int i = 1 ; i < nums.size() ;i++){
            if(nums[i] < prev and !mila){
                mila = true;
            }
            else if(nums[i] < prev and mila){
                ans = false;
                break;
            }
            else{
                prev = nums[i];
            }
        }
        if(ans){
            return true;
        }
        prev = nums[n-1];
        ans = true;
        mila = false;
        for(int i = n-2 ; i >= 0 ;i--){
            if(nums[i] > prev and !mila){
                mila = true;
            }
            else if(nums[i]>prev and mila){
                ans = false;
                break;
            }
            else{
                prev = nums[i];
            }
        }
        return ans;
    }
};