class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0;
        
        int start = 0;
        int curr = 0;
        for(int i = 0 ; i < n ;i++){
            curr += gas[i] - cost[i];
            if(curr < 0){
                start = i+1;
                curr = 0;
            }
            total += gas[i] - cost[i];
        }
        
        if(total >= 0){
            return start;
        }
        
        return -1;
        
    }
};