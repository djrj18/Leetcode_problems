class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets == 1) return 0;
     int round = minutesToTest/minutesToDie+1;
        buckets--;
        int ans = 0;
        while(buckets > 0){
            buckets /= round;
            ans++;
        }
        return ans;
    }
};