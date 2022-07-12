class Solution {
public:
    bool solve(vector<int> &nums, int curr, int &sum ,int i ,int cnt ,int k,vector<int> &visited){
        if(cnt == k-1){
            return true;
        }
        if(curr == sum){
            return solve(nums,0,sum,0,cnt+1,k,visited);
        }
        
        for(int ind = i ; ind < nums.size() ; ind++){
            if(!visited[ind] and curr+nums[ind] <= sum){
                int d = nums[ind];
                visited[ind] = 1;
                if(solve(nums,curr+d,sum,ind+1,cnt,k,visited)){
                    return true;
                }
                visited[ind] = 0;
            }
        }
        
        return false;
    }
  
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = 0 ;
        for(int i = 0 ;i < n ;i++){
            sum += matchsticks[i];
        }
        
        if(sum % 4 != 0){
            return false;
        }
        
        sum /= 4;
        sort(matchsticks.begin(),matchsticks.end());
        vector<int> visited(n,0);
        return solve(matchsticks,0,sum,0,0,4,visited);
        
    }
};