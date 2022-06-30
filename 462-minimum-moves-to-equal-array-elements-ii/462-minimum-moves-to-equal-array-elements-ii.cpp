class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        int ans = 0;
        int mid;
        if(n%2 == 0){
            mid = (nums[n/2 -1]+nums[n/2])/2;
        }
        else{
            mid = nums[n/2];
        }
        for(int i = 0 ; i < n ;i++){
            ans += abs(nums[i] - mid);
        }
        return ans;
    }
};