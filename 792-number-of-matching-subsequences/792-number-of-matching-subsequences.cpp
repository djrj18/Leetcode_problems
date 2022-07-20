class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> ind(26);
        for(int i = 0 ;i < s.length() ; i++){
            ind[s[i] - 'a'].push_back(i);
        }
        
        int ans = 0;
        for(auto str : words){
            int prevInd = -1;
            bool mila = true;
            for(auto ch : str){
                // if(ind[ch - 'a'].size() == 0){
                //     mila = false;
                //     break;
                // }
                int id = upper_bound(ind[ch - 'a'].begin(),ind[ch - 'a'].end(), prevInd) - ind[ch - 'a'].begin();
                if(id == ind[ch - 'a'].size()){
                    mila = false;
                    break;
                }
                prevInd = ind[ch - 'a'][id];
            }
            if(mila){
                ans++;
            }
        }
        
       return ans;
    }
};