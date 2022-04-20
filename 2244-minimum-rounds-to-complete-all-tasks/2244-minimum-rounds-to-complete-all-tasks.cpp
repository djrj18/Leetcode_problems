class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        map<int,int> mp;
        for(int i = 0;i<n;i++){
            mp[tasks[i]]++;
        }
        
        int ans = 0;
        for(auto data : mp){
          if(data.second%3 == 0){
              ans += data.second/3;
          }
          else if(data.second%3 == 2 or (data.second%3 == 1 and data.second > 1)){
              ans += data.second/3 +1;
          }  
          else if(data.second%2 == 0){
              ans += data.second/2;
          }
            else{
                return -1;
            }
        }
        
        return ans;
        
    }
};