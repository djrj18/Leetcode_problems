class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char> st = {'a', 'e', 'o' ,'i', 'u', 'A', 'E' ,'I' ,'O','U'};
        
        int len = s.length();
        
        int cnt = 0;
        
        for(int j = 0 ; j < len/2 ;j++)
        {
            if(st.find(s[j]) != st.end()) cnt++;
        }
        
        for(int j = len/2 ; j < len ;j++)
        {
            if(st.find(s[j]) != st.end()) cnt--;
        }
        
        return cnt == 0;
            
    }
};