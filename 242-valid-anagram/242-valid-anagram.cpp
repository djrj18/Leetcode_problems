class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> T(26,0);
        for(auto ch : s){
            T[ch - 'a']++;
        }
        for(auto ch : t){
            if(T[ch - 'a'] == 0) return false;
            T[ch - 'a']--;
        }
        
        for(int i = 0 ; i < 26 ;i++){
            if(T[i] != 0 ) return false;
        }
        return true;
    }
};