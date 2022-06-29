class Solution {
public:
    static bool cmp(vector<int> v1,vector<int> v2){
        if(v1[0] == v2[0]) return v1[1] < v2[1];
        return v1[0] > v2[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> ans(n);
        ans[0] = people[0];
        for(int i = 1 ; i < n ; i++){
            int ind = people[i][1];
            int k = i-1;
            while(k >= ind){
                ans[k+1] = ans[k];
                k--;
            }
            ans[ind] = people[i];
        }
        return ans;
    }
};