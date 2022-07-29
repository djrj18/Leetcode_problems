class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int count=0;
        int count1=0;
        for(int i=0; i<operations.size();i++){
           if(operations[i]=="++X" || operations[i]=="X++"){
              count++;
           }
            else{
              count1++;
            }
        }
        if(count>=count1){
            return (count-count1);
        }
        else{
         return -(count1-count);
        }
    }
};