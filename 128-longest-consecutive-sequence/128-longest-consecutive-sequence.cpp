class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]] = 1;
        }
        int ans  = 1;
        for(int  i = 0;i<nums.size();i++){
            if(mp.find(nums[i] - 1) == mp.end()){
                int cnt = 1;
                while(mp.find(nums[i]+cnt)!=mp.end()){
                    cnt++;
                }
                ans = max(ans,cnt);
            }
        }
        
        return ans;
    }
};