class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int> ans(m+n);
        int k = 0;
        while( i < m and j < n){
            if(nums1[i] > nums2[j]){
                ans[k++] = nums2[j++];
            }
            else{
                ans[k++] = nums1[i++];
            }
        }
        if(i == m){
            while( j < n ){
                ans[k++] = nums2[j++];
            }
        }
        if(j == n){
            while( i < m ){
                ans[k++] = nums1[i++];
            }
        }
        for(int i = 0 ;i < m+n ;i++){
            nums1[i] = ans[i];
        }
        
    }
};