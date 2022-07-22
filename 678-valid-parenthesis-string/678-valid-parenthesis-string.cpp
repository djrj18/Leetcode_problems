class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<int,char>> star,Open;
        for(int i = 0 ; i < s.length() ;i++){
            char ch = s[i];
            if(ch == '('){
                Open.push({i,ch});
            }
            else if(ch == '*'){
                star.push({i,ch});
            }
            else{
                if(Open.size()){
                    Open.pop();
                }
                else if(star.size()){
                    star.pop();
                }
                else{
                    return false;
                }
            }
        }
        
        if(Open.size() > star.size()){
            return false;
        }
        
        while(Open.size()){
            if(Open.top().first > star.top().first){
                return false;
            }
            Open.pop();
            star.pop();
        }
        return true;
    }
};