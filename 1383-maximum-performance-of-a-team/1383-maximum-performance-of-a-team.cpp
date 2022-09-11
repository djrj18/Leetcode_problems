class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v(n);
        
        for(int i = 0 ; i < n ;i++) v[i] = {efficiency[i], speed[i]};
        sort(v.begin(),v.end());
        
        long long int sum = 0ll;
        long long int ans = 0ll;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = n-1 ; i >= 0 ;i--){
            ans = max(ans, (sum + v[i].second*1ll) * v[i].first*1ll);
            if(k > 1){
            if(pq.size() == k-1){
                int d = pq.top();
                pq.pop();
                if(d < v[i].second){
                    pq.push(v[i].second);
                    sum -= d*1ll;
                    sum += v[i].second*1ll;
                }
                else{
                    pq.push(d);
                }
            }
            else{
                pq.push(v[i].second);
                sum += v[i].second*1ll;
            }
            }
        }
        
        return ans % 1000000007;
        
    }
};