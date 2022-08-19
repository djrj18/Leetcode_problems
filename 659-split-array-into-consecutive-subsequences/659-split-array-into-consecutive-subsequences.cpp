class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        map<int,int> fr, End;
        for(auto nm : nums) fr[nm]++;
        
        for(int i = 0 ; i < n ; i++){
            if(fr[nums[i]]){
                if(End[nums[i]-1]){
                    fr[nums[i]]--;
                    End[nums[i]-1]--;
                    End[nums[i]]++;
                }
                else if(fr[nums[i]+1] and fr[nums[i]+2]){
                    fr[nums[i]+1]--;
                    fr[nums[i]+2]--;
                    fr[nums[i]]--;
                    End[nums[i]+2]++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};