class DSU {
    public:
      vector<int> par;
      vector<int> sz;
      DSU(int n){
          par = vector<int>(n+1);
          sz = vector<int>(n+1);
          for(int i = 0 ; i <= n ;i++){
              par[i] = i;
              sz[i] = 1;
          }
      }
    int FindP(int u){
        if(par[u] == u){
            return u;
        }
        return par[u] = FindP(par[u]);
    }
    
    void Union(int u ,int v){
        int pu = FindP(u);
        int pv = FindP(v);
        if(pu == pv){
            return;
        }
        int szu = sz[pu];
        int szv = sz[pv];
        if(szu > szv){
            par[pv] = pu;
            sz[pu] += szv;
        }else{
            par[pu] =pv;
            sz[pv] += szu;
        }
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU s(n);
        vector<int> ans;
        for(auto ed : edges){
            int p1 = s.FindP(ed[0]);
            int p2 = s.FindP(ed[1]);
            if(p1 == p2){
                ans = ed;
            }else{
                s.Union(ed[0],ed[1]);
            }
        }
        return ans;
    }
};