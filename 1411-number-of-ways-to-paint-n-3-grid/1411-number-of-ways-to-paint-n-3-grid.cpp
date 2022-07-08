class Solution {
public:
    int numOfWays(int n) {
        vector<long long int> diff(n),same(n);
        int mod = 1000000007;
        diff[0] = 6ll;
        same[0] = 6ll;
        for(int i = 1 ; i < n ;i++){
            diff[i] = 2ll*diff[i-1]+2ll*same[i-1];
            same[i] = 2ll*diff[i-1]+3ll*same[i-1];
            diff[i] %= mod;
            same[i] %= mod;
        }
        
        return (diff[n-1]+same[n-1])%mod;
    }
};