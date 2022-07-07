class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> g(n);
        for(auto d : flights){
            int u = d[0];
            int v = d[1];
            int wt = d[2];
            g[u].push_back({v,wt});
        }
        
        vector<vector<int>> dp(n,vector<int>(k+5,INT_MAX));
        dp[src][0] = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>> > pq;
        pq.push({0,src,1});
        
        while(pq.size()){
            vector<int> v = pq.top();
            pq.pop();
            int wt = v[0];
            int node = v[1];
            int Tillk = v[2];
            
            for(auto nb : g[node]){
                int v = nb.first;
                int d = nb.second;
                if(dp[v][Tillk-1] > wt+d and Tillk-1 <= k){
                    dp[v][Tillk-1] = wt+d;
                    pq.push({wt+d,v,Tillk+1});
                }
            }
        }
        
        
        int ans = INT_MAX;
        for(auto d : dp[dst]){
            ans = min(ans,d);
        }
        
        return ans == INT_MAX ? -1 : ans;
        
    }
};