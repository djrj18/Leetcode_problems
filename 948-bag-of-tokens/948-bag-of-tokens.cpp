class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int i = 0,j=n-1;
        int ans = 0, score = 0;
        while(i <= j){
            ans = max(ans,score);
            if(power >= tokens[i]) score++, power -= tokens[i],i++;
            else if(score) power += tokens[j--],score--;
            else return ans;
        }
        return max(ans,score);
    }
};