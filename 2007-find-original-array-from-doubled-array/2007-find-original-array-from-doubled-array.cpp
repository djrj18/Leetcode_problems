class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> ans;
        if(n % 2) return ans;
        map<int,int> mp;
        for(int i = 0;i < n ;i++) mp[changed[i]]++;
        sort(changed.begin(),changed.end());
        for(int i = 0 ; i < n ;i++){
            if(mp[changed[i]] and mp[changed[i]*2]) {mp[changed[i]*2]--;mp[changed[i]]--;ans.push_back(changed[i]);}
        }
        
       for(auto d : mp) if(d.second) return {};
        
       return ans; 
       
        
    }
};