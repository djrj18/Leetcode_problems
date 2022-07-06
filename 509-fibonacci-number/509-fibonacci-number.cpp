class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }
        int SecondLast=0;
        int Last=1;
        for(int i=2;i<=n;i++){
            int a= SecondLast+Last;
            SecondLast=Last;
            Last=a;
        }
        
        return Last;
    }
};