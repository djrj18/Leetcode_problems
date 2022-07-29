class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& v, string s) {
        vector<string> ans;
        int i;
        
        
        for (i=0; i<v.size(); i++){
            string temp=v[i];
            vector<int> mp(26,-1);
            vector<int> vis(26,0);
            
            
            
            bool flag=true;
            
            for (int j=0; j<temp.length(); j++){
                if (mp[s[j]-'a']!=-1 && mp[s[j]-'a']!=(temp[j]-'a')){
                    flag=false;
                    break;
                }
                else if (mp[s[j]-'a']==-1 && vis[temp[j]-'a']){
                    flag=false;
                    break;
                }
             
                mp[s[j]-'a']=(temp[j]-'a');
                vis[temp[j]-'a']++;
            }
            
            if (flag){
                ans.push_back(temp);
            }
        }
        
     return ans;
    }
};