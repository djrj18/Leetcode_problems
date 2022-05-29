class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> v(n);
        for(int i = 0;i<n;i++){
            int d = 0;
            for(int j = 0;j<words[i].length();j++){
                d = d | (1<<(words[i][j]-'a'));
            }
            v[i] = d;
        }
        
        int ans = 0;
    
        for(int i = 0;i < n ; i++){
            for(int j = i+1 ; j < n; j++){
                if((v[i]&v[j]) == 0){
                    ans = max(ans,(int)words[i].length() * (int)words[j].length());
                }
            }
        }
        return ans;
    }
};