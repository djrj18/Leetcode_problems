class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s)   
{
       unordered_map<char, vector<int>> mp;
        for(int i=0; i<s.length() ;i++) 
        {
            //char k=s[i];
            mp[s[i]].push_back(i) ;
        }
        int ans=0;
        for(auto itr:mp)  
        {
           int sz= (itr. second). size() ;
            if(sz>=2) 
            {
                int temp= (itr. second)[sz-1] -(itr. 
                                           second) [0];
                ans=max(ans, temp) ;
            }
        }
        return ans-1;
 }
};