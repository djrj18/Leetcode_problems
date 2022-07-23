class Solution {
public:
    void mergeTwoArray(vector<pair<int,int>> &newNum ,vector<int> &ans,int i,int m,int j){
        vector<pair<int,int>> Temp;
        vector<int> t;
        for(int k = m+1 ; k <= j ;k++){
            t.push_back(newNum[k].first); 
           
        }
        
        int l = i;
        while(l <= m){
            int data = newNum[l].first;
            int ind = newNum[l].second;
            int id = lower_bound(t.begin(),t.end(),data) - t.begin();
    
            ans[ind] += id;
            l++;
        }
              
        l = i;
        int k = m+1;
        while(l <= m and k <= j ){
            if(newNum[l].first > newNum[k].first){
                Temp.push_back(newNum[k]);
                k++;
            }
            else{
                Temp.push_back(newNum[l]);
                l++;
            }
        }
              
        while(l <= m){
            Temp.push_back(newNum[l++]);
        }
        while(k <= j){
            Temp.push_back(newNum[k++]);
        }   
              
              
         for(l = i ; l <= j ;l++){
             newNum[l] = Temp[l-i];
         }     
              
    }
    void Merge(vector<pair<int,int>>&newNum,vector<int> &ans,int i,int j){
        if(i >= j){
            return;
        }
        int m = i+(j-i)/2;
        Merge(newNum,ans,i,m);
        Merge(newNum,ans,m+1,j);
        mergeTwoArray(newNum,ans,i,m,j);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        vector<pair<int,int>> newNum(n);
        for(int i = 0 ; i < nums.size() ;i++){
            newNum[i] = {nums[i],i};
        }
        Merge(newNum,ans,0,n-1);
        return ans;
    }
};