class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        int n = triplets.size();
        
        int x = target[0];
        int y = target[1];
        int z = target[2];
        
        bool Xmila = false,Ymila = false,Zmila = false;
        
        for(int i = 0 ; i < n ;i++){
            
            int a = triplets[i][0];
            int b = triplets[i][1];
            int c = triplets[i][2];
            if(a > x or b > y or c > z) continue;
            if(a == x ){
                Xmila = true;
            }
            if(b == y){
                Ymila = true;
            }
            if(c == z){
                Zmila = true;
            }
            if(Xmila and Ymila and Zmila){
                return true;
            }
        }
        
        return false;
    }
};