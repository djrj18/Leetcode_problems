class Solution {
public:
    int minSteps(string s, string t) {
        int len = s.length();

        map<char,int> fr1, fr2;
        int ans = 0;

        for(int i = 0 ; i < len ;i++)
        {
            fr1[s[i]]++;
            fr2[t[i]]++;

        }

        for(auto ch : fr1)
        {
            if(fr2[ch.first] < ch.second){
                ans += ch.second - fr2[ch.first] ;
            }
        }

        return ans;
    }
};