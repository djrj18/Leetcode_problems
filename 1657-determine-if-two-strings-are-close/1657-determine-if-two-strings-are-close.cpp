class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();

        if(len1 != len2) return false;

       vector<int> fr1(26,0);
       vector<int> fr2(26,0);
       vector<int> chrs1(26,0);
       vector<int> chrs2(26,0); 

        for(int i = 0 ; i < len1 ; i++)
        {
            fr1[word1[i] - 'a']++;
            fr2[word2[i] - 'a']++;
            chrs1[word1[i]-'a'] = 1;
            chrs2[word2[i] - 'a'] = 1;
        }

        if(chrs1 != chrs2) return false;

        sort(fr1.begin(), fr1.end());
        sort(fr2.begin(), fr2.end());




        

        return fr1 == fr2;


        
    }
};