class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> fr;
        for(auto num : arr) fr[num]++;
        priority_queue<pair<int,int>> pq;
        for(auto d : fr) pq.push({d.second,d.first});
        
        int n = arr.size();
        int k  = n;
        int ans = 0;
        while( k > n/2){
            pair<int,int> p = pq.top();
            pq.pop();
            k -= p.first;
            ans++;
        }
        return ans;
    }
};