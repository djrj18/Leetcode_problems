class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;
        
        int a;
        int b;
        while(left<right){
            if(numbers[left]+numbers[right]==target){
                a=left+1;
                b=right+1;
                break;
            }
            
            else if (numbers[left]+numbers[right]<target){
                left++;
            }
            
            else{
                right--;
            }
        }
        
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        
        return ans;
    }
};