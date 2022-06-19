class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>> ans;
        int left = 0;
        int right = products.size()-1;
        for(int i = 0 ; i < searchWord.length() ; i++){
            char ch = searchWord[i];
            vector<string> t;
            while(left <= right and (products[left].length() == i or products[left][i] < ch)) left++;
            while(right >= left and (products[right].length()  == i or products[right][i] > ch)) right--;
            for(int j = 0 ; j < 3 and j+left <= right ; j++){
                t.push_back(products[j+left]);
            }
            ans.push_back(t);
        }
        return ans;
    }
};