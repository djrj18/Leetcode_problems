class Solution {
public:
    pair<int,int> solve(vector<vector<int>> &G,string &s,int src){
        
        if(G[src].size() == 0){
            return {1,1};
        }
        pair<int,int> ans;
        int a = 1,b=1,c=1;
        for(auto nbr : G[src]){
            pair<int,int> p = solve(G,s,nbr);
            if(s[nbr] != s[src]){
                if(a < p.second+1){
                    b = a;
                    a = p.second+1;
                }
                else if(a == p.second+1){
                    b = a;
                }
                else if(p.second+1 > b){
                    b = p.second+1;
                }
            }
            c = max(c,p.first);
        }
        
        ans = {max(c,a+b-1),a};
        return ans;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> G(n);
        for(int i = 1;i<n;i++){
            G[parent[i]].push_back(i);
        }
        return solve(G,s,0).first;
        
    }
};