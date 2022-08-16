class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> fr(26,0);
        for(char ch : s) fr[ch - 'a']++;
        for(int i = 0 ; i < s.length() ;i++){
            if(fr[s[i]-'a'] == 1) return i; 
        }
        return -1;
    }
};