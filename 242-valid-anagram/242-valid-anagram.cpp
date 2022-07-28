class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> T(26,0);
        int l = s.length();
        if(l != t.length()) return false;
        for(int i = 0 ; i < l ; i++){
            T[s[i] - 'a']++;
            T[t[i] - 'a']--;
        }
        
        for(int i = 0 ; i < 26 ;i++){
            if(T[i] != 0 ) return false;
        }
        return true;
    }
};