class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        int n = flowers.size();
        sort(flowers.begin(),flowers.end());
        vector<long long int> Need(n);
        Need[0] = 0ll;
        for(int i = 1 ; i < n ;i++){
            Need[i] = Need[i-1]+(long long)(flowers[i] - flowers[i-1])*(long long)i;
        }
        
        int ind = n-1;
        while(ind >= 0 and flowers[ind] >= target){
            ind--;
        }
        long long int ans = 0;
        int i ;
       
        for(i = ind ; i >= 0 ;i--){
            int id = upper_bound(Need.begin(),Need.begin()+(i+1),newFlowers) - Need.begin();
            long long int rem = newFlowers - Need[id-1];
            long long int Extra = rem/(long long)id;
            int Maxmin = min((long long)flowers[id-1]+Extra,(long long)target-1ll);
            long long int prt = (long long)Maxmin*(long long)partial;
            long long int fll = (long long)full*(long long)(n - i-1);
            ans = max(ans,prt+fll);
            newFlowers -= (target - flowers[i]);
            if(newFlowers < 0){
                break;
            }
        }
       
        if(i < 0){
            ans = max(ans,(long long)full*(long long)n);
        }
        return ans;
        
    }
};