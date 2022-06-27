class Solution {
public:
    int minPartitions(string n) {
        int Mx = 0;
        for(int i = 0 ;i < n.length() ;i++){
            if(n[i] - '0' > Mx){
                Mx = n[i] - '0';
            }
        }
        return Mx;
    }
};