class Solution {
public:
    int gcd(int p,int q){
        if(p%q==0)
            return q;
        return gcd(q,p%q);
    }
    int mirrorReflection(int p, int q) {
        int lcm=(p*q)/gcd(p,q);
        int lbp=lcm/p;
        int lbq=lcm/q;
        if(lbp%2==0)
            return 0;
        if(lbq%2==0)
            return 2;
        return 1;
    }
};