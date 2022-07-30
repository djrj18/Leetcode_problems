class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
       unordered_map<char,int> maxFr;
       for(auto st : words2){
           unordered_map<char,int> t;
           for(auto ch : st) t[ch]++;
           for(auto d : t) maxFr[d.first] = max(d.second, maxFr[d.first]);
       }
        
       vector<string> ans;
        for(auto st : words1){
            unordered_map<char,int> t;
            for(auto ch :st) t[ch]++;
            bool mila = true;
            for(char ch = 'a' ; ch <= 'z' ;ch++){
                if(t[ch] < maxFr[ch]){
                    mila = false;
                    break;
                }
            }
            
            if(mila) ans.push_back(st);
        }
        return ans;
    }
};