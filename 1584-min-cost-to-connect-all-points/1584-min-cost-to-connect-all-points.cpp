class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> g(n);
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < n ;j++){
                if(i != j){
                    int d = abs(points[i][0] - points[j][0])+abs(points[i][1] - points[j][1]);
                    g[i].push_back({j,d});
                    g[j].push_back({i,d});
                }
            }
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> visited(n,0),dis(n,INT_MAX);
        dis[0] = 0;
        while(pq.size()){
            pair<int,int> p = pq.top();
            pq.pop();
            int d = p.first;
            int node = p.second;
            visited[node] = 1;
            for(auto nb : g[node]){
                if(!visited[nb.first] and dis[nb.first] > nb.second){
                    dis[nb.first] = nb.second;
                    pq.push({nb.second,nb.first});
                }
            }
        }
        
        int ans = 0;
        for(auto d : dis){
           
            ans += d;
        }
        
        return ans;
    }
};