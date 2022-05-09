class Solution {
public:
    vector<string>strs = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> solve(string digits,int start,int len){
        if(start == len){
            return {""};
        }
        
        vector<string> ans;
        vector<string> get = solve(digits,start+1,len);
        for(auto ch : strs[digits[start]-'0']){
            for(auto data : get){
                string s = "";
                s += ch;
                s += data;
                ans.push_back(s);
            }
        }
        
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        int l = digits.length();
        if(l == 0){
            return ans;
        }
       ans =  solve(digits,0,l);
        return ans;
        
    }
};