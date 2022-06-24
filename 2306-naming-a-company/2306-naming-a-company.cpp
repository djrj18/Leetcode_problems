class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> s;
        for(auto st : ideas){
            s.insert(st);
        }
        vector<vector<long long int>> dp(26,vector<long long int>(26,0));
        
        for(auto st : ideas){
            string str = st;
            for(char ch = 'a' ; ch <= 'z' ;ch++){
                str[0] = ch;
                if(s.count(str) == 0){
                    dp[st[0]-'a'][ch-'a']++;
                }
            }
        }
        long long int ans = 0ll;
        for(int i = 0 ; i < 26 ;i++){
            for(int j = 0 ;j < 26 ;j++){
                ans += (dp[i][j]*dp[j][i]);
            }
        }
        return ans;
        
    }
};