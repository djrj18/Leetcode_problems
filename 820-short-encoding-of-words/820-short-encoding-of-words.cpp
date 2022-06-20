class Solution {
public:
    static bool cmp(string s1, string s2){
        return s1.length() > s2.length();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        map<string,int> mp;
        for(auto st : words){
            mp[st] = 1;
        }
        
        int ans = 0;
        for(int i = 0 ; i < words.size() ; i++){
            string s = words[i];
            if(mp[s] != 0){
                ans += s.length()+1;
            }
            
            for(int j = s.length()-1 ; j >= 0 ;j--){
                string sub = s.substr(j);
                mp[sub] = 0;
            }
        }
        return ans;
    }
};