class Solution {
public:
    void solve(vector<vector<int>> &G,int src,vector<int>&intime,vector<int>&lowtime,vector<vector<int>> &ans,int p){
        static int t = 0;
        intime[src] = t;
        lowtime[src] = t;
        t++;
        for(auto nbr : G[src]){
            if(nbr == p){
                continue;
            }
            else if(intime[nbr] != -1){
                lowtime[src] = min(lowtime[src],lowtime[nbr]);
               
            }
            else{
                 
                solve(G,nbr,intime,lowtime,ans,src);
                if(lowtime[nbr] > intime[src]){
                    ans.push_back({src,nbr});
                }
                lowtime[src] = min(lowtime[src],lowtime[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> G(n);
        for(auto data : connections){
            int ai = data[0];
            int bi = data[1];
            G[ai].push_back(bi);
            G[bi].push_back(ai);
        }
        
        vector<vector<int>> ans;
        vector<int> intime(n,-1),lowtime(n);
        solve(G,0,intime,lowtime,ans,-1);
        return ans;   
    }
};