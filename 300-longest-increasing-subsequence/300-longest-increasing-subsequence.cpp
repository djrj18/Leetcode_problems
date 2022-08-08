class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        v[0] = nums[0];
        int l = 1;
        for(int i = 1;i<n;i++){
            //cout<<v[l-1]<<endl;
            if(nums[i] <= v[0]){
                v[0] = nums[i];
            }
            else if (nums[i] > v[l-1]){
                v[l++] = nums[i];
            }
            else{
                int left = 0;
                int right = l-1;
                int ind = l-1;
                while(left<=right){
                    int m = left+(right - left)/2;
                    if(v[m] < nums[i]){
                        left = m+1;
                    }
                    else{
                        right = m-1;
                        ind = m;
                    }
                }
                
                v[ind] = nums[i];
            }
           // cout<<l<<endl;
        }
        
        return l;
    }
};