class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int y = arr[1]-arr[0];
        bool x= false;
        for(int i=1; i<n; i++){
          if(arr[i]-arr[i-1]!=y){
             x = false;
              break;
          }
            else{
              x = true;
            }
        }
        return x;
    }
};