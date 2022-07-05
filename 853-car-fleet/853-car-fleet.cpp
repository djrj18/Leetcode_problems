class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>> v(n);
        for(int i = 0 ; i < n ;i++){
            v[i] = {position[i],speed[i]};
        }
        sort(v.begin(),v.end());
        stack<int> st;
        st.push(n-1);
        
        for(int i = n-2 ; i >= 0 ; i--){
            if((long long)(target - v[st.top()].first)*(long long)v[i].second >= (long long)(target - v[i].first)*(long long)v[st.top()].second){
                continue;
            }else{
                st.push(i);
            }
        }
        
        return st.size();
    }
};