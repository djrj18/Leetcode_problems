class Solution {
public:
    bool solve(vector<vector<int>> &graph,int src,int stVal,vector<int> &st){
        st[src] = stVal;
        for(auto nbrs : graph[src]){
            if(st[nbrs] != -1){
                if(st[nbrs] == stVal){
                    return false;
                }
            }
            else if(solve(graph,nbrs,stVal^1,st) == false){
                return false;
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> st(n,-1);
        
       for(int i = 0;i<n;i++){
           if(st[i] == -1){
               bool ans = solve(graph,i,0,st);
               if(ans == false){
                   return false;
               }
           }
       }
        return true;
        
    }
};