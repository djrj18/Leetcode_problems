class Solution {
public:
    static bool cmp(pair<int,int> p1,pair<int,int> p2){
        if(p1.first == p2.first) return p1.second > p2.second;
        return p1.first < p2.first;
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        vector<pair<int,int>> v(n);
        for(int i = 0 ; i < n ;i++){
            int a = properties[i][0];
            int b = properties[i][1];
            v[i] = {a,b};
        }
        int ans  = 0;
        sort(v.begin(), v.end(), cmp);
        int mx_d = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            if(mx_d > v[i].second) ans++;
            else mx_d = v[i].second;
        }
        
        return ans;
    }
};