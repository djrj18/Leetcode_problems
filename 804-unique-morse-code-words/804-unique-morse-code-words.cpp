class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> st;
        
        for(auto d : words){
            string s = "";
            for(auto ch : d){
                s += v[ch-'a'];
            }
            st.insert(s);
        }
        return st.size();
    }
};