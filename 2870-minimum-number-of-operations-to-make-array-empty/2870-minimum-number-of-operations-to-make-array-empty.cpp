class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(auto i : nums) mp[i]++;
        
        int ans = 0;
        
        for(auto itr : mp){
            int fr = itr.second;
            if(fr == 1) return -1;
            int q = fr/3;
            int r = fr%3;
            if(r == 0 or r%2 == 0) {
                ans += q;
            if(r != 0){
                ans += r/2;
            }
        }else{
                ans += q+1;
            }
            
           
        
        
    }
        return ans;
    }
};