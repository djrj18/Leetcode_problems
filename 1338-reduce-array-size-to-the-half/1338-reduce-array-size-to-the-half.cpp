class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> fr;
        vector<int> v;
        
        for(auto num : arr) fr[num]++;
        for(auto d : fr) v.push_back(d.second);
        
        int n = arr.size();
        int k  = n;
        sort(v.begin(),v.end());
        int i = v.size() -1;
        int ans = 0;
        while( k > n/2){
            k -= v[i--];
            ans++;
        }
        return ans;
    }
};