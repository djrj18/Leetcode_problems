class Solution {
public:
    int len(long long int d){
        int ans = 0;
        while(d){
            ans++;
            d /= 10;
        }
        return ans;
    }
//     long long int num(vector<int> &digits){
//         long long int ans = 0ll;
//         for(int i = 0 ;i <digits.size() ;i++){
//             ans *= 10ll;
//             ans += 1ll*digits[i];
//         }
//         return ans;
//     }
//     bool check(vector<int> &digits, map<long long int, bool> &mp,int start,int len){
//         if(start >= len) return false;
//         if(mp[num(digits)])return true;
        
//         for(int i = start ; i < len ; i++){
//             if(start == 0 and digits[i] == 0) continue;
//             swap(digits[i],digits[start]);
//             bool t = check(digits, mp,start+1,len);
//             if(t) return true;
//             swap(digits[i],digits[start]);
//         }
        
//         return false;
//     }
    vector<int> digits(int n){
        vector<int> digit;
        while(n){
            int t = n%10;
            n = n/10;
            digit.push_back(t);
        }
        return digit;
    }
    bool reorderedPowerOf2(int n) {
        // method 1 using recursion
        
//         long long int d = 1;
//         vector<map<long long int, bool>> v(9);
        
//         while(d <= 1e9){
//             int l = len(d);
//             v[l-1][d] = true;
//             d *= 2ll;
//         }
        
//         vector<int> digits;
//         int l = len(n);
//         while(n){
//             int t = n%10;
//             n = n/10;
//             digits.push_back(t);
//         }
        
//         return check(digits, v[l-1],0,l);
        
        // method 2 
        int l = len(n);
        vector<int> digi = digits(n);
        sort(digi.begin(), digi.end()); 
        int sm = pow(10, l-1);
        int smallestTwoPower = log2(sm);
        smallestTwoPower = pow(2, smallestTwoPower);
        int high = pow(10,l);
        vector<int> TwoPowers;
        while(smallestTwoPower <= high){
            TwoPowers.push_back(smallestTwoPower);
            smallestTwoPower *= 2;
        }
        
        for(auto num : TwoPowers){
            vector<int> t = digits(num);
            sort(t.begin(), t.end());
            if(digi == t) return true;
        }
        return false;
        
        
    }
};