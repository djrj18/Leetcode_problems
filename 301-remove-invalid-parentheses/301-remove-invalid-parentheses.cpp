class Solution {
public:
    pair<set<string>,int> solve(string &s ,int i ,int j ,vector<vector<pair<set<string>,int>>> & dp){
        if(i > j){
            return {{""},0};
        }
        if(dp[i][j].first.size() != 0){
            return dp[i][j];
        }
        pair<set<string>,int> pF;
        int min = INT_MAX;
        if((s[i] == '(' and s[j] == ')')){
            pair<set<string>,int> p1 = solve(s,i+1,j-1,dp);
            for(auto str : p1.first){
                string sl = "";
                sl += s[i];
                sl+= str;
                sl += s[j];
                pF.first.insert(sl);
            }
            pF.second = p1.second;
            min = pF.second;
        }
        for(int k = i ; k < j ;k++){
            pair<set<string>,int> p1 = solve(s,i,k,dp);
            pair<set<string>,int> p2 = solve(s,k+1,j,dp);
            
            if(p1.second+p2.second < min){
               set<string> t;
                for(auto str1 : p1.first){
                    for(auto str2 : p2.first){
                        string str = str1+str2;
                        t.insert(str);
                    }
                }
                pF.first = t;
                min = p1.second+p2.second;
                pF.second = min;
            }else if(min == p1.second+p2.second){
                for(auto str1 : p1.first){
                    for(auto str2 : p2.first){
                        string str = str1+str2;
                        pF.first.insert(str);
                    }
                }
            }
        }
        
//         if(s[i] == '(' and s[j] == ')'){
//             pair<set<string>,int> p = solve(s,i+1,j-1,dp);
//             for(auto st : p.first){
//                 pF.first.insert("("+st+")");
//             }
//             pF.second = p.second;
//         }else if(s[i] >= 'a' and s[i] <= 'z'){
//             pair<set<string>,int> p = solve(s,i+1,j-1,dp);
//             for(auto st : p.first){
//                 string sl = "";
//                 sl += s[i];
//                 sl += st;
//                 sl += s[j];
//                 pF.first.insert(sl);
//             }
//             pF.second = p.second;
//         }else{
//             pair<set<string>,int> p1 = solve(s,i+1,j,dp);
//             pair<set<string>,int> p2 = solve(s,i,j-1,dp);
//             if(p1.second > p2.second){
//                 pF.first = p2.first;
//                 pF.second = 1+p2.second;
//             }else if(p1.second == p2.second){
//                 pF.first = p1.first;
//                 for(auto st : p2.first){
//                     pF.first.insert(st);
//                 }
//                 pF.second = 1+p1.second;
//             }else{
//                 pF.first = p1.first;
//                 pF.second = 1+p1.second;
//             }
//         }
        
        return dp[i][j] = pF;
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        vector<vector<pair<set<string>,int>>> dp(n,vector<pair<set<string>, int>>(n));
        for(int i = 0 ; i < n ;i++){
            set<string> st;
            if(s[i] >= 'a' and s[i] <= 'z'){
                string str = "";
                str += s[i];
                st.insert(str);
                dp[i][i] = {st,0};
            }else{
                st.insert("");
                dp[i][i] = {st,1};
            }
        }
        set<string> st = solve(s,0,n-1,dp).first;
        vector<string>ans;
        for(auto str : st){
            ans.push_back(str);
        }
        
        // for(int G=  0 ;G < n ;G++){
        //     int i = 0;
        //     int j = G+i;
        //     while(j < n){
        //         cout<<i<<" "<<j<<endl;
        //         for(auto str : dp[i][j].first){
        //             cout<<str<<" "<<dp[i][j].second<<" ";
        //         }
        //         cout<<endl;
        //         i++;
        //         j++;
        //     }
        // }
        return ans;
    }
};