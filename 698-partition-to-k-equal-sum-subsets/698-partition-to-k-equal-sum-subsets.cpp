class Solution {
public:
bool canPartitionKSubsets(vector<int>& nums, int k) {

    int sum = 0;
    for(auto &i : nums)
        sum += i;
    
    if(sum % k)
        return false;
    
    map<int, bool> mp;
    int x = 0, target = sum / k;
    
    return helper(nums, x, 0, target, k, mp);
}

bool helper(vector<int> &nums, int &x, int sum, int &target, int k, map<int, bool> &mp)
{
    if(k == 1)
        return true;
    
    if(sum == target)
        return helper(nums, x, 0, target, k - 1, mp);
    
    if(sum > target)
        return false;
    
    if(mp.find(x) != mp.end())
        return mp[x];
    
    for(int i = 0; i < nums.size(); i++)
        if(!((x >> i) & 1))
        {
            x |= (1 << i);
        
            if(sum + nums[i] <= target && helper(nums, x, sum + nums[i], target, k, mp))
                return mp[x] = true;
            
            x ^= (1 << i);
        }
            
    return mp[x] = false;
}
};