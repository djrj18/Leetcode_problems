class DSU{
    private:
       vector<int> par;
       vector<int> sz;
    public:
       int size;
       DSU(int n){
           par = vector<int>(n);
           sz = vector<int>(n);
           for(int i = 0 ; i < n ;i++){
               par[i] = i;
               sz[i] = 1;
           }
           size = 1;
       }
    
      int FindP(int u){
          if(par[u] == u){
              return u;
          }
          return par[u] = FindP(par[u]);
      }
    
    void Union(int u,int v){
        int Pu = FindP(u);
        int Pv = FindP(v);
        if(Pu == Pv){
            return ;
        }
        int szU = sz[Pu];
        int szV = sz[Pv];
        if(szU > szV){
            par[Pv] = Pu;
            sz[Pu] += sz[Pv];
            size = sz[Pu];
        }else{
            par[Pu] = Pv;
            sz[Pv] += sz[Pu];
            size = sz[Pv];
        }
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
      priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i = 0 ; i < n ;i++){
            for(int j = 1 ; j < n ;j++){
                    int d = abs(points[i][0] - points[j][0])+abs(points[i][1] - points[j][1]);
                    pq.push({d,{i,j}});
                }
        }
        
        DSU s(n);
        int ans = 0;
        while(pq.size()){
            pair<int,pair<int,int>> p = pq.top();
            pq.pop();
            int u = p.second.first;
            int v = p.second.second;
            int Pu = s.FindP(u);
            int Pv = s.FindP(v);
            if(Pu != Pv){
                ans += p.first;
                s.Union(u,v);
                if(s.size == n){
                    return ans;
                }
            }
        }
        return ans;
    }
};