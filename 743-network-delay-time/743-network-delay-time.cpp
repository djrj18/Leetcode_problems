class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> G(n+1);
        for(int i = 0;i<times.size();i++){
            int src = times[i][0];
            int des = times[i][1];
            int w = times[i][2];
            G[src].push_back({des,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,k});
        vector<int> Dis(n+1,INT_MAX);
        vector<int>visited(n+1,0);
        int ans =  0 ;
        Dis[k] = 0;
        while(q.size()){
            pair<int,int> p = q.top();
            q.pop();
            if(visited[p.second] == 0){
            ans = max(ans,p.first);
            visited[p.second] = 1;
            for(auto nbr : G[p.second]){
                if(visited[nbr.first] == 0 and Dis[nbr.first] > Dis[p.second]+nbr.second){
                    Dis[nbr.first] = Dis[p.second]+nbr.second;
                    q.push({Dis[nbr.first],nbr.first});
                }
            }
            }
        }
        
        for(int i = 1;i<=n;i++){
            if(Dis[i] == INT_MAX){
                return -1;
            }
        }
        
        return ans;
        
    }
};