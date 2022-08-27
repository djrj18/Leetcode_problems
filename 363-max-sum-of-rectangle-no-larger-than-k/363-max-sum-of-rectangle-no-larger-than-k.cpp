class Solution {
public:
    
    int maxSumArray(vector<int> &v,int k){
        
        int n = v.size();
        set<int> st;
        st.insert(0);
        int sum = 0;
        int mx = INT_MIN;
        
        for(int i = 0 ; i < n ;i++){
            sum += v[i];
            auto it = st.lower_bound(sum - k);
            if(it != st.end()) mx = max(mx, sum - *it);
            st.insert(sum);
        }
        
        return mx;
    }
    
    
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0 ; i < n ;i++){
            for(int j = 1 ;j < m ;j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        int mx = INT_MIN;
        
        for(int i = 0 ;i < m ;i++){
            for(int j = i ;j < m ;j++){
                vector<int> v;
                for(int l = 0 ; l < n ;l++){
                   int cs = matrix[l][j];
                   if(i > 0) cs -= matrix[l][i-1];
                   v.push_back(cs); 
                }
               int curr = maxSumArray(v,k);
               mx = max(mx,curr);
                
            }
        }
        return mx;
    }
};