class Solution {
public:
    static bool cmp(pair<int,int>p1,pair<int,int> p2){
        return p1.first > p2.first;
    }
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<pair<int,int>>> G(n);
        for(auto data : edges){
            int a = data[0];
            int b = data[1];
            G[a].push_back({scores[b],b});
            G[b].push_back({scores[a],a});
        }
        for(int i = 0;i<n;i++){
            sort(G[i].begin(),G[i].end(),cmp);
        }
        int ans = -1;
        for(auto data : edges){
            int u = data[0];
            int v = data[1];
            for(int i = 0;i<min(3,(int)G[u].size());i++){
                int x = G[u][i].second;
                if(x == v){continue;}
                for(int j = 0;j<min(3,(int)G[v].size());j++){
                    int y = G[v][j].second;
                    if(y == x or y == u){
                        continue;
                    }
                    ans = max(ans,scores[u]+scores[v]+scores[x]+scores[y]);
                }
            }
            
        }
        return ans;
    }
};