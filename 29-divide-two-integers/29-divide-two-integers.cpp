class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int a = (long long)dividend;
        long long int b = (long long)divisor;
        int sign = 0;
        if(a < 0){
            a = -a;
            sign = 1;
        }
        if(b < 0){
            b = -b;
            sign = sign ^ 1;
        }
        
        if(b == 1){
            if(sign == 0){
                return a >= pow(2,31) ? pow(2,31) -1 : a;
            }
            return a > pow(2,31) ? -pow(2,31) : -a;
        }
        int ans = 0;
        while(a >= b){
          long long int c = b;
          while(c <= a){
              c = c*b;
          }
          if(c > a){
              a -= (c/b);
              ans += (c/(b*b));
          }
            else{
                a -= c;
                ans += (c/b);
            }
            
        }
        // cout<<ans<<sign<<endl;
        if(sign == 0){
            return ans >= pow(2,31) ? pow(2,31) -1  : ans;
        }
      
        return ans > pow(2,31) ? (-1)*pow(2,31) : -ans;
        
    }
};