class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        int n = rectangles.size();
        int m = points.size();
        vector<vector<int>> arr(n+1,vector<int>(105,0));
        sort(rectangles.begin(),rectangles.end());
         for(int i = n-1;i>=0;i--){
            for(int j = 1;j<=100;j++){
                if(rectangles[i][1] >= j){
                    arr[i][j] = arr[i+1][j]+1;
                }
                else{
                    arr[i][j] = arr[i+1][j];
                }
            }
        }
        vector<int> ans(m,0);
        for(int i = 0;i<m;i++){
            int left = 0;
            int right = n-1;
            int ind = -1;
            while(left <= right){
                int mid = left+(right - left)/2;
                if(rectangles[mid][0] >=  points[i][0]){
                    ind = mid;
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            if(ind != -1){
               ans[i] = arr[ind][points[i][1]];
            }
        }
        return ans;
        
    }
};