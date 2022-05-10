class Solution {
public:
    int mod = 1000000007;
    int countTexts(string pressedKeys) {
        int n = pressedKeys.length();
        vector<long int> dp(n+1);
        dp[n] = 1;
        dp[n-1] = 1;
        for(int i = n-2;i>=0;i--){
            dp[i] = dp[i+1];
            if(i < n-1 and pressedKeys[i] == pressedKeys[i+1]){
                dp[i] += dp[i+2];
            }
            if(i < n-2 and pressedKeys[i] == pressedKeys[i+1] and pressedKeys[i+1] == pressedKeys[i+2]){
                dp[i] += dp[i+3];
            }
            if(i < n-3 and (pressedKeys[i] == '9' or pressedKeys[i] == '7') and pressedKeys[i] == pressedKeys[i+1] and pressedKeys[i+1] == pressedKeys[i+2] and pressedKeys[i+2] == pressedKeys[i+3]){
                dp[i] += dp[i+4];
            }
            
            dp[i] %= mod;
        }
       return dp[0];
    }
};