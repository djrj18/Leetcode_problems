class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        priority_queue<int> pq;
        
        int currFuel = startFuel;
        int currPos = 0;
        int ans = 0;
        for(int i = 0; i < n ;i++){
            if(currPos >= target) return ans;
            int pos = stations[i][0];
            int fuel = stations[i][1];
            
            int need = pos - currPos;
            
            if(currFuel >= need){
                currFuel -= need;
            }
            else{
                while(pq.size() and need > currFuel){
                    int f = pq.top();
                    pq.pop();
                    currFuel += f;
                    ans++;
                }
                if(currFuel < need) return -1;
                currFuel -= need;
            }
             
             currPos = pos;
             pq.push(fuel);
        }
        
        int need = target - currPos; 
        while(pq.size() and need > currFuel){
             int f = pq.top();
             pq.pop();
             ans++;
             currFuel += f;
        }
        
        if(need > currFuel) return -1;
        
        return ans;
        
    }
};