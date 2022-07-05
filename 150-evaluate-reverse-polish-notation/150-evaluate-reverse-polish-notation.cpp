class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> Operands;
        for(int i = 0 ; i < tokens.size() ;i++){
            if(tokens[i] == "+"){
                int d1 = stoi(Operands.top());
                Operands.pop();
                int d2 = stoi(Operands.top());
                Operands.pop();
                int d = d1+d2;
                Operands.push(to_string(d));
            }else if(tokens[i] == "-"){
                 int d1 = stoi(Operands.top());
                Operands.pop();
                int d2 = stoi(Operands.top());
                Operands.pop();
                int d = d2-d1;
                Operands.push(to_string(d));
                
            }else if(tokens[i] == "*"){
                 int d1 = stoi(Operands.top());
                Operands.pop();
                int d2 = stoi(Operands.top());
                Operands.pop();
                int d = d1*d2;
                Operands.push(to_string(d));
                
            }else if(tokens[i] == "/"){
                 int d1 = stoi(Operands.top());
                Operands.pop();
                int d2 = stoi(Operands.top());
                Operands.pop();
                int d = d2/d1;
                Operands.push(to_string(d));
                
            }else{
                Operands.push(tokens[i]);
            }
        }
        
        return stoi(Operands.top());
        
    }
};