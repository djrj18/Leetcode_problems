class Solution {
public:
    static bool cmp(vector<int> v1 , vector<int> v2){
        return v1[1] > v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans = 0;
        for(int i = 0 ; i < boxTypes.size() ;i++){
            int BoxInc = min(boxTypes[i][0],truckSize);
            ans += BoxInc*boxTypes[i][1];
            truckSize -= BoxInc;
            if(truckSize == 0){
                return ans;
            }
        }
        return ans;
    }
};