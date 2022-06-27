class Solution {
public:
    int Xor(vector<vector<int>> &Tree,int src,int par,vector<int> &nums,vector<int> &x){
        int x_or = 0;
        for(auto nbr : Tree[src]){
            if(nbr != par){
                x_or ^= Xor(Tree,nbr,src,nums,x);
            }
        }
        return x[src] = x_or^nums[src];
        
    }
    void Ancestors(vector<vector<int>> &Tree,int root,vector<vector<int>> &ac,int par = -1){
        for(auto nb : Tree[root]){
            if(nb != par){
                Ancestors(Tree,nb,ac,root);
                for(int i = 0 ; i < ac.size() ; i++){
                    ac[root][i] = ac[root][i] || ac[nb][i];
                }
                ac[root][nb] = 1;
            }
        }
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> Tree(n);
        for(auto nb : edges){
            int a = nb[0];
            int b = nb[1];
            Tree[a].push_back(b);
            Tree[b].push_back(a);
        }
        vector<int> x(n);
        
        Xor(Tree,0,-1,nums,x);
        
        int ans = INT_MAX;
        vector<vector<int>> ac(n,vector<int>(n,0));
        Ancestors(Tree,0,ac);
      for(int i = 1 ;i < n ;i++){
          for(int j = 1 ; j < n ;j++){
              if(j != i){
              int a ,b, c;
              if(ac[j][i] == 1){
                  a = x[i];
                  b = x[j]^a;
                  c = x[0]^x[j];
              }else if(ac[i][j] == 1){
                  a = x[j];
                  b = x[i]^a;
                  c = x[0]^x[i];
              }else{
                  a = x[i];
                  b = x[j];
                  c = x[0]^a^b;
              }
              ans = min(ans, max({a,b,c}) - min({a,b,c}));    
          }
          }
      }
        
        return ans;
        
        
    }
};