class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> v(n,vector<int>(26,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<words[i].length();j++){
                v[i][words[i][j]-'a'] = 1;
            }
        }
        
        int ans = 0;
    
        for(int i = 0;i < n ; i++){
            for(int j = i+1 ; j < n; j++){
                bool mila= true;
                for(int k = 0;k<26;k++){
                    if(v[i][k] == v[j][k] and v[i][k] != 0){
                        mila = false;
                        break;
                    }
                }
                if(mila){     ans = max(ans,(int)words[i].length() * (int)words[j].length());}
            }
        }
        return ans;
    }
};