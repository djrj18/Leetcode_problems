class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        map<int,int> mp;
        for(int i = 0;i<n;i++){
            mp[tasks[i]]++;
        }
        
        int ans = 0;
        for(auto data :mp){
            if(data.second == 1){
                return -1;
            }
            if(data.second%3 == 0){
                ans += data.second/3;
            }
            else{
                ans += data.second/3 + 1;
            }
        }
        return ans;
        
    }
};