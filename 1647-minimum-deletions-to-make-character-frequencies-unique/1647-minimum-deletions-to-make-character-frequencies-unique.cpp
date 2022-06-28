class Solution {
public:
    int minDeletions(string s) {
        vector<int> fr(26,0);
        
        for(int i = 0 ; i < s.length(); i++){
            fr[s[i] - 'a']++;
        }
        sort(fr.begin(),fr.end());
        int ans = 0;
        
        for(int i = 24; i >= 0 and fr[i] > 0 ;i--){
            if(fr[i] < fr[i+1]){
                continue;
            }
            ans += fr[i] - fr[i+1]+1;
            fr[i] = fr[i+1]-1;
            if(fr[i] == 0){
                while(i >= 0){
                    ans += fr[i];
                    i--;
                }
            }
        }
        return ans;
        
    }
};