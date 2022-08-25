class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> fr1(26,0),fr2(26,0);
        for(auto ch : ransomNote) fr1[ch-'a']++;
        for(auto ch : magazine) fr2[ch-'a']++;
        
        for(int i = 0 ; i < 26 ;i++){
            if(fr1[i] > fr2[i]) return false;
        }
        
        return true;
    }
};