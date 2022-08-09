class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int,bool> mp;
        map<int , long long int> trees;
        for(auto d : arr) {
            mp[d] = true;
            trees[d] = 1ll;
        }   
        int mod = 1e9+7;
        sort(arr.begin(),arr.end());
        
        for(int i = 0 ; i < arr.size() ;i++){
            for(int j = 0 ; j < arr.size() ;j++){
                if(arr[i] %arr[j] == 0){
                    int d1 = arr[i]/arr[j];
                    long long int data = 0ll;
                    if(d1 < arr[j]) break;
                    if(d1 >= arr[j] and mp[d1] and mp[arr[j]]) data = (trees[d1]*trees[arr[j]])%mod;
                    if(d1 != arr[j]) data *= 2ll;
                    trees[arr[i]] = (trees[arr[i]]+data)%mod;
                }
            }
        }
        
        long long int ans = 0ll;
        
        for(int i = 0 ; i < arr.size() ;i++){
            ans += trees[arr[i]];
            ans %= mod;
        }
        
        return ans;
        
    }
};