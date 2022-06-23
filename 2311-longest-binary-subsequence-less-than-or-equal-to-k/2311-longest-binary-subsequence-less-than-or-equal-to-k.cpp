class Solution {
public:
    int longestSubsequence(string s, int k) {
        int p = 0;
        long long int num = 0ll;
        int ind = -1;
        int NoOfBits = 0;
        int d = k;
        if(k == 0){
            NoOfBits = 1;
        }
        while(d){
            NoOfBits++;
            d = d >> 1;
        }
        for(int i = s.length()-1; i >= 0 and NoOfBits >= 0 ; i--){
            if(s[i] == '1'){
                num += (long long)pow(2,p);
            }
            if(num > k){
                ind = i;
                break;
            }
            p++;
            NoOfBits--;
            ind = i;
        }
        
        int ans = p;
        for(int i = 0 ; i < ind ; i++){
            if(s[i] == '0'){
                ans++;
            }
        }
        
        return ans;
        
    }
};