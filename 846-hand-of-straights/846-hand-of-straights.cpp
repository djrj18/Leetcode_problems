class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0){
            return false;
        }
        sort(hand.begin(), hand.end());
        map<int,int> fr;
        for(int i = 0 ; i < n; i++){
            fr[hand[i]]++;
        }
        
        for(int i = 0 ; i < n ;i++){
            if(fr[hand[i]] != 0){
                int d = groupSize;
                int t = hand[i];
                while(d--){
                    if(fr[t] == 0){
                        return false;
                    }
                    fr[t]--;
                    t++;
                }
            }
        }
        
        return true;
    }
};