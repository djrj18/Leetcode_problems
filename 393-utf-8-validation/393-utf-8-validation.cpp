class Solution {
public:
    vector<int> bits(int n){
        vector<int> v;
        for(int i = 0 ;i < 8 ;i++){
            int d = n&1;
            v.push_back(d);
            n = n >> 1;
        }
        reverse(v.begin(),v.end());
        return v;
    }
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        int i = 0 ;
        while(i < n){
            vector<int> bit = bits(data[i]);
            int k = 0;
            while(k < 8 and bit[k] == 1) k++;
            if(k > 4) return false;
            if(k == 0) i++;
            else if(k == 1) return false;
            else{
                if(n - i -1 < k-1) return false;
                i++;
                k--;
                while(i < n and k){
                    vector<int> bit = bits(data[i]);
                    if(bit[0] != 1 or bit[1] != 0) return false;
                    i++;
                    k--;
                }
            }
        }
        
        return true;
    }
};