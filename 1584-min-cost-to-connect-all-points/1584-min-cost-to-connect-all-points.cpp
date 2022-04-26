class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        map<int,vector<pair<int,int>>> nbrs;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int cost = abs(points[i][0] - points[j][0])+abs(points[i][1] - points[j][1]);
                nbrs[i].push_back({j,cost});
                nbrs[j].push_back({i,cost});
            }
        }
        
        vector<int> dis(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> q;
        vector<bool> visited(n,false);
        q.push({0,0});
        int ans = 0;
        while(q.size()){
            pair<int,int> p = q.top();
            q.pop();
            if(visited[p.second] == false){
                  ans += p.first;
                  //cout<<p.first<<" ";
            }
        
            visited[p.second] = true;
            for(auto nbr : nbrs[p.second]){
                if(visited[nbr.first] == false and dis[nbr.first] > nbr.second){
                    dis[nbr.first] = nbr.second;
                    q.push({nbr.second,nbr.first});
                }
            }
        }
        
        return ans;
        
    }
};