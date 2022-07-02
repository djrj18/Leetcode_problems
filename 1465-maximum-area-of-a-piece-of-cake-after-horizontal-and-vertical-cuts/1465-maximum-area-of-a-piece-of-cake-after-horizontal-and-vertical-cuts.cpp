class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int maxH = 0;
        int maxV = 0;
        for(int i = 1 ; i < horizontalCuts.size() ;i++){
            maxH = max(maxH,horizontalCuts[i] - horizontalCuts[i-1]);
        }
        for(int i = 1 ; i < verticalCuts.size() ;i++){
            maxV = max(maxV,verticalCuts[i] - verticalCuts[i-1]);
        }
        
        
        return ((long long)maxH*(long long)maxV)%1000000007;
        
        
    }
};