class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int upper_bound = 0;
        int right_bound = n-1;
        int left_bound = 0;
        int down_bound = n-1;
        int dir = 0;
        vector<vector<int>> ans(n,vector<int>(n));
        int data = 1;
        while(data <= n*n){
            if(dir == 0){
                int j = left_bound;
                while(j <= right_bound){
                    ans[upper_bound][j] = data++;
                    j++;
                }
                 upper_bound++;
                 dir = 1;
            }
            else if(dir == 1){
                int i = upper_bound;
                while(i <= down_bound){
                    ans[i][right_bound] = data++;
                    i++;
                }
                right_bound--;
                dir = 2;
            }
            else if (dir == 2){
                int j = right_bound;
                while( j >= left_bound){
                    ans[down_bound][j] = data++;
                    j--;
                }
                dir = 3;
                down_bound--;
            }
            else{
                int i = down_bound;
                while(i >= upper_bound){
                    ans[i][left_bound] = data++;
                    i--;
                }
                dir = 0;
                left_bound++;
            }
        }
        
        return ans;
    }
};