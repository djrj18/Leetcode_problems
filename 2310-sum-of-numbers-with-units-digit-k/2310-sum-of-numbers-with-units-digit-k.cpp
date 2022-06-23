class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num == 0){
            return 0;
        }
        if(k == 0){
            if(num%10 == 0){
                return 1;
            }
            return -1;
        }
        int cnt = 0;
        while(num >= 0){
            if(num%10 == k){
                return cnt+1;
            }
            num -= k;
            cnt++;
        }
        return -1;
        
    }
};