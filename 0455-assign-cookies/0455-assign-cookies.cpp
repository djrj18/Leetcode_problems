class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i =0,j = 0, ans = 0;
        while(i < n and j < m){
            if(g[i] <= s[j]){
                i++;
                j++;
                ans++;
            }else{
                j++;
            }
        }
        return ans;
    }
};