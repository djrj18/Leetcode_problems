class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int j = m-1; j >= 0 ;j--){
            int i = 0;
            int k = j;
            vector<int> v;
            while(k < m and i < n){
                v.push_back(mat[i][k]);
                i++;
                k++;
            }
            sort(v.begin(),v.end());
            int s = 0;
            i = 0;
            k = j;
            while(k < m and i < n){
                mat[i][k] = v[s];
                i++;
                k++;
                s++;
            }
        }
        
        for(int i = 1 ; i < n ;i++){
            int j = 0;
            int k = i;
            vector<int> v;
            while(k < n and j < m){
                v.push_back(mat[k][j]);
                k++;
                j++;
            }
            sort(v.begin(), v.end());
            int s = 0;
            j = 0;
            k = i;
            while(k < n and j < m){
                mat[k][j] = v[s];
                k++;
                j++;
                s++;
            }
        }
        
        return mat;
    }
};