class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ind = k-1;
        int score = 0;
        for(int i = 0 ; i < k ;i++){
            score += cardPoints[i];
        }
        int last = cardPoints.size()-1;
        int ans = 0;
        while(ind >= 0){
            ans = max(ans,score);
            score -= cardPoints[ind--];
            score += cardPoints[last--];
        }
        ans = max(ans,score);
        return ans;
        
    }
};