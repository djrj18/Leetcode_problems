class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k){
            string tmp = "";
            for(int i = 0;i<s.length();i += k){
                int data = 0;
                for(int j = i;j<min(i+k,(int)s.length());j++){
                    data += s[j]-'0';
                }
                tmp += to_string(data);
            }
            s = tmp;
        }
        return s;
    }
};