class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if(n-k+1 < k){
            return false;
        }
        int total = pow(2,k);
        vector<int> v(total,0);
        int CurrNumber = 0;
        int start = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(i - start +1 <= k){
                CurrNumber = CurrNumber*2+(s[i]-'0');
            }
            else{
                v[CurrNumber] = 1;
                CurrNumber = (CurrNumber - (s[start++]-'0')*pow(2,k-1))*2+(s[i]-'0');
            }
        }
        v[CurrNumber] = 1;
        for(int i = 0 ; i < total ; i++){
            if(v[i] == 0){
                return false;
            }
        }
        
        return true;
        
    }
};