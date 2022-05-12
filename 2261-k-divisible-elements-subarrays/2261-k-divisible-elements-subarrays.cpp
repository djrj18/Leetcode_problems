class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        int ans = 0;
        set<string> st;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            string s = "";
            int cnt = 0;
            for(int j = i;j<n;j++){
               s += to_string(nums[j])+".";
                if(nums[j]%p == 0){
                    cnt++;
                }
                if(cnt >k){
                    break;
                }
              
             st.insert(s);
                
            }
        }
        return st.size();
        
    }
};