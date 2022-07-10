class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int Last= 0;
        int SecondLast= 0;
         for(int i=2;i<=cost.size();i++){
             int a= min(Last+cost[i-1],SecondLast+cost[i-2]);
             SecondLast= Last;
             Last= a;
         }
        
        return Last;
    }
};