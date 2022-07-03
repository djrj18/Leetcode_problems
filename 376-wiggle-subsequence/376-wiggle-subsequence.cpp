class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return nums[0] == nums[1]?1:2;
        }
        vector<pair<int,int>> p(n);
        p[0] = {1,1};
        int ans = 1;
        for(int i = 1;i<nums.size();i++){
            p[i] = {1,1};
            for(int j = 0;j<i;j++){
                if(nums[j]  - nums[i] > 0){
                    p[i].first = max(p[i].first,p[j].second+1);
                }
                if(nums[j] - nums[i] < 0){
                    p[i].second = max(p[i].second,p[j].first+1);
                }
            }
            ans = max(ans,max(p[i].first,p[i].second));
        }
        return ans;
    }
};