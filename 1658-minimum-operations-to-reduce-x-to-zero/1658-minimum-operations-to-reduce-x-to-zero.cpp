
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int n = nums.size();
        int ans = INT_MAX, sum = 0;
        map<int,int> mp;
        for(int i = n - 1;i >=0;i--) {
            sum += nums[i];
            mp[sum] = i + 1;
            if(sum == x) ans = min(ans,n - i);
        }
        sum = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            if(sum == x) ans = min(ans,i + 1);
            if(mp[x-sum] != 0 && mp[x-sum] - 1> i) ans = min(ans,i + n - mp[x - sum] + 2);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};