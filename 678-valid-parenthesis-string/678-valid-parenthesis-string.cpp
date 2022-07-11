class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<int,char>> star,open;
        for(int i = 0 ; i < s.length() ;i++){
            if(s[i] == '('){
                open.push({i,s[i]});
            }else if(s[i] == '*'){
                star.push({i,s[i]});
            }else{
                if(!open.empty()){
                    open.pop();
                }else if(!star.empty()){
                    star.pop();
                }else{
                    return false;
                }
            }
        }
        
        while(open.size()){
            if(star.size() == 0){
                return false;
            }
            if(open.top().first > star.top().first){
                return false;
            }
            open.pop();
            star.pop();
        }
        
        return true;
        
    }
};