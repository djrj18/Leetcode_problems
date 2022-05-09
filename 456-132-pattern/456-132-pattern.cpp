class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> small(n);
        
        small[0] = nums[0];
        for(int i = 1;i<n;i++){
           if(small[i-1]<= nums[i]){
               small[i] = small[i-1];
           }
            else{
                small[i] = nums[i];
            }
        }
        
        stack<int> st;
        st.push(n-1);
        for(int i = n-2;i>0;i--){
           while(st.size() and (nums[st.top()] <= small[i-1])){
               st.pop();
           }
           if(st.size() and nums[i] > nums[st.top()]){
               return true;
           } 
           st.push(i); 
        }
        
        return false;
        
    }
};