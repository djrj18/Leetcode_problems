class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int mila=-1;
        
        for(int i=0; i<sentences.size();i++){
         mila=max(mila, int(count(sentences[i].begin(),sentences[i].end(),' ')+1));
        }
        return mila;
    }
};