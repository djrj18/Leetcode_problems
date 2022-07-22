class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> ind(26);
        for(int i = 0 ; i < n ;i++){
            ind[s[i] - 'a'] = i;
        }
        
        vector<int> ans;
        
        int preMax = 0;
        int start = 0;
        for(int i = 0 ; i < n ;i++){
            if(i > preMax){
                ans.push_back(i - start);
                start = i;
            }
            preMax = max(preMax,ind[s[i]-'a']);
        }
        ans.push_back(n - start);
        return ans;
    }
};